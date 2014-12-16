
/*
 * datatypes.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    /* "short" is no longer than "int", which is no longer than "long". */
    /* "shot int" < "int" < "long int" */

    int var1 = 0;
    short int var2 = 0;
    long int var3 = 0;

    /* "short int" at least 16 bits (2 bytes) */
    fprintf(stdout, "short int\t=\t%d bytes\t(%d bits)\n", \
            sizeof(short int), (sizeof(var1)*8));

    /* "int" at least 16 bits (2 bytes) or 32 bits (4 bytes) */
    fprintf(stdout, "int\t\t=\t%d bytes\t(%d bits)\n", \
            sizeof(int), (sizeof(var2)*8));

    /* "long int" at least 32 bits (4 bytes) or 64 bits (8 bytes) */
    fprintf(stdout, "long int\t=\t%d bytes\t(%d bits)\n", \
            sizeof(long int), (sizeof(var3)*8));

    /* "char" 1 byte */
    char var4 = 65; /* ASCII 'A' character */
    /* signed char - 1 byte, -128-127 */
    signed char var5 = -127;
    /* "unsugned char - 1 byte, 0-255 */
    unsigned char var6 = 255;

    fprintf(stdout, "char = %c\n", var4);
    fprintf(stdout, "char = %d\n", var5);
    fprintf(stdout, "char = %d\n", var6);

return 0;
}


