
/*
 * strncat.c
 * Victor Erminpour
 * (C) 2018
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char src[10] = "DEADBEEF";
    char dst[10] = "dst";

    strncat(dst,src,4);
    printf("%s\n",dst);

return 0;
}

