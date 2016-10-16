
/* array_init.c */
/* Victor Hugo Erminpour */
#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size, char *name)
{
    int count = 0;
    fprintf(stdout, "Printing %s[%d]\n", name, size); 
    for (count=0; count < size; count++)
    {
        fprintf(stdout, "array[%d]\t=\t%d\n", count, array[count]); 
    }
}

int main(int argc, char *argv[])
{

    int int_array[5] = {[0 ... 4] = 0};
    int a[5] = { [4] = 29, [2] = 15 };
    int b[5] = { 0, 0, 15, 0, 29 };
    int c[5] = { [0 ... 1] = 1, [2 ... 3] = 2, [4] = 3 };
    int d[5] = { [0] = 0, 1, 2, [3] = 3 };

    print_array(int_array, 5, "int_array");
    print_array(a, 5, "a");
    print_array(b, 5, "b");
    print_array(c, 5, "c");
    print_array(d, 5, "d");

return 0;
}


