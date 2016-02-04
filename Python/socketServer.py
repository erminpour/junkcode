#!/usr/bin/python -tt

import socket
import time

def main():
    ## Create server socket
    socketfd = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    hostname = '' 
    portnum = 31337

    ## set socket options before bind()
    socketfd.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    socketfd.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
    socketfd.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, 20)
    socketfd.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, 5)
    socketfd.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, 6)

    ## bind() to hostname/port tuple
    socketfd.bind((hostname, portnum))

    ## listen() and change form active to 
    ## passive socket with backlog of 5
    socketfd.listen(5)

    while True:
        clientfd, remoteAddress = socketfd.accept()
        IPADDR, PORT = remoteAddress
        print "Connected! IPADDR =  %s, PORT = %d" % (IPADDR, PORT)
        clientfd.send("Connected! Sleeping...\n")
        time.sleep(10) # 1 minute
        clientfd.send("That's all folks!\n")
        clientfd.close()

if __name__ == '__main__':
    main()


