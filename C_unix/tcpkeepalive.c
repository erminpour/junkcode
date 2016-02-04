
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

int main(void){
    int sock_fd;
    int optval = 1;
    unsigned int optlen = sizeof(optval);
    int rdoptval,goptval;

    sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    getsockopt(sock_fd, SOL_SOCKET, SO_KEEPALIVE, (void*)&goptval, &optlen);
    setsockopt(sock_fd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
    getsockopt(sock_fd, SOL_SOCKET, SO_KEEPALIVE, (void*)&rdoptval, &optlen);
    close(sock_fd);
    
    printf("before SO_KEEPALIVE:%d\n", goptval);
    printf("after SO_KEEPALIVE:%d\n", rdoptval);

    return 0;
}
