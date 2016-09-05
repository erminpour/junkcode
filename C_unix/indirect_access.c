
/* indirect_access.c - Passing pointers to function */

#include <stdio.h>

void incr(int *ptr)
{
    //*ptr = *ptr + 1;
    (*ptr)++;
}

int main (int argc, char *argv[])
{

    int num = 42;
    fprintf(stdout, "Original value of num: %d\n", num);
    incr(&num);
    fprintf(stdout, "New value of num: %d\n", num);

return 0;
}


