/*
 * print_netdevice.c
 * Victor Hugo Erminpour
 */ 

#include <stdio.h>
#include <stdlib.h>

/* socket() */
#include <sys/types.h>
#include <sys/socket.h>

/* netdevice */
#include <sys/ioctl.h>
#include <net/if.h>

/* memset(), string functions */
#include <string.h>

static void print_queuelen(const char *name)
{

    struct ifreq ifr;
    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        exit(1);

    memset(&ifr, 0, sizeof(struct ifreq));

    strncpy(ifr.ifr_name, name, strlen(name));
    if (ioctl(sock, SIOCGIFTXQLEN, &ifr) < 0)
    {
        fprintf(stdout, "ioctl() Error\n");
        close(sock);
        exit(1);
    }
    close(sock);

    if(ifr.ifr_qlen)
        fprintf(stdout, "qlen = %d\n", ifr.ifr_qlen);

}

int main(int argc, char *argv[])
{
    print_queuelen("eth0");

return 0;
}

