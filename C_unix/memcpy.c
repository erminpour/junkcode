
/*
 * memcpy.c
 * Victor Erminpour
 * (C) 2018
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    void *vdest_ptr = NULL;
    char *dest_ptr = NULL;
    char src[] = "memcpy()";
    char dest[50];

    fprintf(stdout, "src = %s\n", src);
    fprintf(stdout, "dest = %s\n", dest);

    vdest_ptr = memcpy(dest, src, strlen(src));
    dest_ptr = (char *)vdest_ptr;
    dest_ptr[strlen(src)] = '\0';
    /* dest[strlen(src)] = '\0'; */

    fprintf(stdout, "src = %s\n", src);
    fprintf(stdout, "dest = %s\n", dest);
    fprintf(stdout, "dest_ptr = %s\n", (char *)dest_ptr);

return 0;
}



