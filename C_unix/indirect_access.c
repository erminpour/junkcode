
/* indirect_access.c - Passing pointers to function */

#include <stdio.h>

void incr(int *ptr)
{
    //*ptr = *ptr + 1;
    (*ptr)++;
    fprintf(stdout, "%s: Address of &ptr = %p\n", __FUNCTION__, &ptr);
    fprintf(stdout, "%s: Value of ptr = %p\n", __FUNCTION__, ptr);
    fprintf(stdout, "%s: Value of *ptr = %d\n", __FUNCTION__, *ptr);
}

int main (int argc, char *argv[])
{

    int num = 42;
    fprintf(stdout, "%s: Value of num: %d\n", __FUNCTION__, num);
    fprintf(stdout, "%s: Address of &num = %p\n", __FUNCTION__, &num);
    incr(&num);
    fprintf(stdout, "%s: New value of num: %d\n", __FUNCTION__, num);
    fprintf(stdout, "%s: Address of &num = %p\n", __FUNCTION__, &num);

return 0;
}


