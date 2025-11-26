"""Lightweight UDP-based multiplayer helper for testing and prototyping.
Provides a simple server that echoes/forwards position updates and clients that
send their own position and receive others'. Not suitable for production.
"""
from __future__ import annotations

import socket
import threading
import time
import logging
from typing import Callable, Dict, Tuple

BUFFER_SIZE = 4096


class UDPLobbyServer:
    """Simple UDP lobby server that forwards messages between clients.

    This server maintains a set of recent client addresses and forwards
    received datagrams to other connected clients. Designed for testing
    and prototyping only.
    """

    def __init__(self, host: str = "0.0.0.0", port: int = 50000):
        self.addr = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(self.addr)
        self.running = False
        self.lock = threading.Lock()
        self.clients: Dict[Tuple[str, int], float] = {}
        self.thread: threading.Thread | None = None

    def start(self) -> None:
        """Start the server loop in a background thread."""
        if self.running:
            return
        self.running = True
        self.thread = threading.Thread(target=self._loop, daemon=True)
        self.thread.start()

    def stop(self) -> None:
        """Stop the server and close the socket."""
        self.running = False
        if self.thread and self.thread.is_alive():
            self.thread.join(timeout=1.0)
        try:
            self.sock.close()
        except OSError as exc:
            # socket close can fail on some platforms; log for debug
            # (don't raise to keep stop() idempotent)
            logging.debug("UDPLobbyServer.sock.close() failed: %s", exc)

    def _loop(self) -> None:
        """Main receive loop: accept datagrams and forward to peers."""
        while self.running:
            try:
                data, addr = self.sock.recvfrom(BUFFER_SIZE)
            except OSError:
                break
            # register client and forward
            with self.lock:
                self.clients[addr] = time.time()
                for client_addr in list(self.clients.keys()):
                    if client_addr == addr:
                        continue
                    try:
                        self.sock.sendto(data, client_addr)
                    except OSError:
                        pass
            # clean up old clients
            now = time.time()
            with self.lock:
                for c in list(self.clients.keys()):
                    if now - self.clients[c] > 30.0:
                        del self.clients[c]


class UDPClient:
    """Lightweight UDP client that can send messages and invoke a callback
    when messages arrive from the server.
    """

    def __init__(self, host: str, port: int, on_message: Callable[[str], None] | None = None):
        self.server = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.running = False
        self.on_message = on_message
        self.thread: threading.Thread | None = None

    def start(self) -> None:
        """Start the listening thread for incoming messages."""
        if self.running:
            return
        self.running = True
        self.thread = threading.Thread(target=self._listen, daemon=True)
        self.thread.start()

    def stop(self) -> None:
        """Stop the client and close resources."""
        self.running = False
        # Attempt to join listener thread; joining may raise RuntimeError
        try:
            if self.thread and self.thread.is_alive():
                self.thread.join(timeout=0.5)
        except RuntimeError:
            # thread state may have changed; ignore
            pass
        try:
            self.sock.close()
        except OSError:
            # ignore socket close failures
            pass

    def send(self, message: str) -> None:
        """Send a UTF-8 encoded message to the configured server address."""
        try:
            self.sock.sendto(message.encode("utf-8"), self.server)
        except OSError:
            # Ignore transient socket failures
            pass

    def _listen(self) -> None:
        """Listen for datagrams from the server and call `on_message` with
        decoded text payloads.
        """
        try:
            self.sock.bind(("", 0))
        except OSError:
            return
        while self.running:
            try:
                data, _addr = self.sock.recvfrom(BUFFER_SIZE)
            except OSError:
                break
            # decode bytes into string; ignore undecodable bytes
            try:
                msg = data.decode("utf-8", errors="ignore")
            except UnicodeDecodeError:
                # ignore malformed packets
                continue

            if self.on_message:
                # Let callback exceptions propagate so they're visible during
                # development rather than silently swallowed.
                self.on_message(msg)
