
/* ptr_types.c
 * Victor Erminpour
 * (C) 2018
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    fprintf(stdout, "sizeof(int *)\t= %d\n", sizeof(int *) );
    fprintf(stdout, "sizeof(int)\t= %d\n", sizeof(int) );
    fprintf(stdout, "sizeof(double *)\t= %d\n", sizeof(double *));
    fprintf(stdout, "sizeof(double)\t= %d\n", sizeof(double));
    fprintf(stdout, "sizeof(char *)\t= %d\n", sizeof(char *));
    fprintf(stdout, "sizeof(char)\t= %d\n", sizeof(char));
    fprintf(stdout, "sizeof(char **)\t= %d\n", sizeof(char **));

return 0;
}

