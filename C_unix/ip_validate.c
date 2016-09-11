
/* ip_validate.c */
/* Victor Ermminpour */
#include <stdio.h>
#include <arpa/inet.h> /* inet_pton() */
#include <netinet/in.h> /* struct in_addr */

#define FALSE 0
#define TRUE !FALSE

int is_ipv4(const char *str)
{
    int ret = -1;
    struct in_addr dest;

    ret = inet_pton(AF_INET, str, &dest);
    if (ret > 0) { 
        return TRUE;
    }    
    return FALSE;
}

int is_ipv6(const char *str)
{
    int ret = -1;
    struct in_addr dest;

    ret = inet_pton(AF_INET6, str, &dest);
    if (ret > 0) { 
        return TRUE;
    }    
    return FALSE;
}


int main(int argc, char *argv[])
{

    fprintf(stdout, "is_ipv4(127.0.0.1)\t%d\n", is_ipv4("127.0.0.1"));
    fprintf(stdout, "ip_ipv4(127.0.0.256)\t%d\n", is_ipv4("127.0.0.256"));
    fprintf(stdout, "is_ipv6(127.0.0.1)\t%d\n", is_ipv6("127.0.0.1"));
    fprintf(stdout, "is_ipv6(2001:db8:a0b:12f0::1)\t%d\n", is_ipv6("2001:db8:a0b:12f0::1"));
    fprintf(stdout, "is_ipv6(::1)\t%d\n", is_ipv6("::1"));

    if(is_ipv6("sandwich"))
        printf("IPv6\n");
    else
        printf("Not IPv6\n");

    if(is_ipv6("::1"))
        printf("IPv6\n");
    else
        printf("Not IPv6\n");
return 0;
}


