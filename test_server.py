from socket import *

sock = socket(AF_INET, SOCK_STREAM)
sock.bind(
    ('0.0.0.0', 2290)
)
sock.listen(0)

while True:
    client, address = sock.accept()
    client.settimeout(5)
    while True:
        received = client.recv(10000)
        if (len(received)) == 0:
            break
        else:
            print(received, 'utf-8')
    client.close()
    # end
