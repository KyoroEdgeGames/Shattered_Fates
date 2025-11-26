import threading
import time

from tools.multiplayer import UDPLobbyServer, UDPClient


def test_udp_lobby_forwards_pos():
    """Start a UDPLobbyServer and two UDPClient instances. Ensure a POS
    message from client A is forwarded to client B.
    """
    server = UDPLobbyServer(host="127.0.0.1", port=0)
    server.start()
    # Determine actual server port (port 0 chooses a free port)
    port = server.sock.getsockname()[1]

    received = []
    ev = threading.Event()

    def on_msg_b(msg: str) -> None:
        received.append(msg)
        ev.set()

    def on_msg_a(_msg: str) -> None:
        # A doesn't need to react in this test
        return

    client_a = UDPClient("127.0.0.1", port, on_message=on_msg_a)
    client_b = UDPClient("127.0.0.1", port, on_message=on_msg_b)
    client_a.start()
    client_b.start()

    try:
        # Register both clients with a short hello so server knows their addresses
        client_a.send("HELLO|A")
        client_b.send("HELLO|B")
        # Allow server to process registration
        time.sleep(0.1)

        # Send a position message from A and assert B receives it
        client_a.send("POS|A|10|20")

        assert ev.wait(timeout=2.0), f"No message received by client B: {received}"
        assert any(m.startswith("POS|A|") for m in received)
    finally:
        client_a.stop()
        client_b.stop()
        server.stop()
