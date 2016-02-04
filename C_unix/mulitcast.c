
/* 
 * multicast.c
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define EXAMPLE_GROUP "239.0.0.1"
#define EXAMPLE_PORT 31337

main(int argc)
{
   struct sockaddr_in addr;
   int addrlen, sock, cnt;
   struct ip_mreq mreq;
   char message[4096];

   /* set up socket */
   sock = socket(AF_INET, SOCK_DGRAM, 0);
   if (sock < 0) {
     perror("socket");
     exit(1);
   }
   bzero((char *)&addr, sizeof(addr));
   addr.sin_family = AF_INET;
   addr.sin_addr.s_addr = htonl(INADDR_ANY);
   addr.sin_port = htons(EXAMPLE_PORT);
   addrlen = sizeof(addr);

   if (argc > 1) {
      /* send */
      addr.sin_addr.s_addr = inet_addr(EXAMPLE_GROUP);
      while (1) {
     time_t t = time(0);
     sprintf(message, "time is %-24.24s", ctime(&t));
     printf("sending: %s\n", message);
     cnt = sendto(sock, message, sizeof(message), 0,
              (struct sockaddr *) &addr, addrlen);
     if (cnt < 0) {
        perror("sendto");
        exit(1);
     }
     sleep(5);
      }
   } else {

      /* receive */
      if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {        
         perror("bind");
     exit(1);
      }    
      mreq.imr_multiaddr.s_addr = inet_addr(EXAMPLE_GROUP);         
      mreq.imr_interface.s_addr = htonl(INADDR_ANY);         
      if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP,
             &mreq, sizeof(mreq)) < 0) {
     perror("setsockopt mreq");
     exit(1);
      }         
      while (1) {
     cnt = recvfrom(sock, message, sizeof(message), 0, 
            (struct sockaddr *) &addr, &addrlen);
     if (cnt < 0) {
        perror("recvfrom");
        exit(1);
     } else if (cnt == 0) {
        break;
     }
     printf("%s: message = \"%s\"\n", inet_ntoa(addr.sin_addr), message);
        }
    }
}