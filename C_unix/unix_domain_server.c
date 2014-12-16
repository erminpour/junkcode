
#include <stdio.h>
#include <stdlib.h>

/* Unix Domain Sockets */
#include <sys/un.h>
#include <sys/socket.h>

/*
 *  struct sockaddr_un {
 *      sa_family_t sun_family; // AF_UNIX
 *      char sun_path[108];     // Null-terminated pathname.
 *
 *  };
 *  Note: "sun_" stands for "socket unix" not Sun Microsystems.
 */

const char *SOCKET_FILE = "/tmp/socketfile";

int
main(int argc, char *argv)
{

    int sfd;
    struct sockaddr_un addr;

    /* memcpy and truncate the string to the 
     * (sizeof(addr.sun_path) -1). The -1 at 
     * the end certifies that this field has 
     * a terminating NULL byte.
     */
    memset(&addr, 0, sizeof(struct sockaddr_un));
    strncpy(addr.sun_path, SOCKET_FILE, sizeof(addr.sun_path) - 1);
    addr.sun_family = AF_UNIX;

    fprintf(stdout, "\taddr.sun_path\t=\t%s\n\taddr.sun_family\t=\t%d\n", \
            addr.sun_path, addr.sun_family);

    /* Create AF_UNIX stream socket. */
    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sfd == -1) {
        fprintf(stderr, "ERROR: socket(AF_UNIX)");
        exit(1);
    }

    if(bind(sfd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        fprintf(stderr, "ERROR: bind()");
        exit(2);
    }

return 0;
}


