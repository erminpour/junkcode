
/* tcp_fastopen.c
 * Victor Erminpour
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>     /* strerror() */
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>     /* IPPROTO_TCP */
#include <netinet/tcp.h>    /* SOL_TCP */


int main(int argc, char *argv[])
{

    int socket_fd = 0;
    int queue_len = 10;

    /* Setup dummy TCP/IPv4 socket */
    if((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))<0)
    {
        fprintf(stderr,"socket(): %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

#ifdef TCP_FASTOPEN
    if(setsockopt(socket_fd, SOL_TCP, TCP_FASTOPEN, &queue_len, sizeof(queue_len)) < 0)
    {
        fprintf(stderr,"setsockopt(): %s\n", strerror(errno));
        close(socket_fd);
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "TCP_FASTOPEN: enabled\n");
#else
    fprintf(stderr, "TCP_FASTOPEN: disabled\n");
    close(socket_fd);
    exit(EXIT_FAILURE);
#endif

close(socket_fd);
return EXIT_SUCCESS;
}

