
/*
 * pass_by.c
 * Victor Hugo Emrinpour
 */

#include <stdio.h>
#include <stdlib.h>

void pass_by_value(int var)
{
    var = 42;
}

void pass_by_reference(int *var)
{
    *var = 42;
}

int main(int argc, char *argv[])
{

    int myvar = 0;
    pass_by_value(myvar);
    /* myvar = 0 */
    fprintf(stdout, "%d\n", myvar);
    pass_by_reference(&myvar);
    /* myvar = 42 */
    fprintf(stdout, "%d\n", myvar);

return 0;
}

