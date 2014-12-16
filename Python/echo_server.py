#!/usr/bin/python

import socket

def main():
    host = '' 
    port = 31337
    backlog = 5
    size=4096

    s_fd = socket.socket(socket.AF_INET, \
                        socket.SOCK_STREAM)
    s_fd.bind((host, port))
    s_fd.listen(backlog)

    while 1:
        client, address = s_fd.accept()
        data = client.recv(size)
        if data:
            client.send(data)
        client.close() 

if __name__ == "__main__":
    main()

