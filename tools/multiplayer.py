"""Lightweight UDP-based multiplayer helper for testing and prototyping.
Provides a simple server that echoes/forwards position updates and clients that
send their own position and receive others'. Not suitable for production.
"""
from __future__ import annotations

import socket
import threading
import time
from typing import Callable, Dict, Tuple

BUFFER_SIZE = 4096


class UDPLobbyServer:
    def __init__(self, host: str = "0.0.0.0", port: int = 50000):
        self.addr = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(self.addr)
        self.running = False
        self.lock = threading.Lock()
        self.clients: Dict[Tuple[str, int], float] = {}
        self.thread: threading.Thread | None = None

    def start(self) -> None:
        if self.running:
            return
        self.running = True
        self.thread = threading.Thread(target=self._loop, daemon=True)
        self.thread.start()

    def stop(self) -> None:
        self.running = False
        if self.thread and self.thread.is_alive():
            self.thread.join(timeout=1.0)
        try:
            self.sock.close()
        except Exception:
            pass

    def _loop(self) -> None:
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
    def __init__(self, host: str, port: int, on_message: Callable[[str], None] | None = None):
        self.server = (host, port)
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.running = False
        self.on_message = on_message
        self.thread: threading.Thread | None = None

    def start(self) -> None:
        if self.running:
            return
        self.running = True
        self.thread = threading.Thread(target=self._listen, daemon=True)
        self.thread.start()

    def stop(self) -> None:
        self.running = False
        try:
            if self.thread and self.thread.is_alive():
                self.thread.join(timeout=0.5)
        except Exception:
            pass
        try:
            self.sock.close()
        except Exception:
            pass

    def send(self, message: str) -> None:
        try:
            self.sock.sendto(message.encode("utf-8"), self.server)
        except OSError:
            pass

    def _listen(self) -> None:
        try:
            self.sock.bind(("", 0))
        except OSError:
            return
        while self.running:
            try:
                data, _addr = self.sock.recvfrom(BUFFER_SIZE)
            except OSError:
                break
            try:
                msg = data.decode("utf-8", errors="ignore")
                if self.on_message:
                    self.on_message(msg)
            except Exception:
                pass
