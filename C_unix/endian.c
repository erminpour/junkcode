
/*
 * endian.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

#define  IS_BIG_ENDIAN     (1 == htons(1))
#define  IS_LITTLE_ENDIAN  (!IS_BIG_ENDIAN)

int main(int argc, char *argv[])
{
#ifdef IS_BIG_ENDIAN
    printf("Big Endian\n");
#else
    printf("Little Endian\n");
#endif

return 0;
}

