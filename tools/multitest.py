from tools.multiplayer import UDPLobbyServer, UDPClient
import time

msgs = []

def onmsg(m):
    print("received:", m)
    msgs.append(m)

print('Starting server on port 50010')
s = UDPLobbyServer(port=50010)
s.start()

print('Starting client A and B')
c1 = UDPClient('127.0.0.1', 50010, on_message=onmsg)
c2 = UDPClient('127.0.0.1', 50010, on_message=onmsg)
c1.start()
c2.start()

time.sleep(0.2)
print('Client A sending POS|A|100|200')
c1.send('POS|A|100|200')

time.sleep(0.5)
print('Client B sending POS|B|300|400')
c2.send('POS|B|300|400')

# allow messages to propagate
time.sleep(0.5)

print('Stopping clients and server')
c1.stop()
c2.stop()
s.stop()
print('Collected messages:', msgs)
