
/*
 * double_ptr.c
 * Victor Erminpour
 * (c) 2018 */

#include <stdio.h>

/* Double pointer, not to be confused with pointer to double. */

int main(int argc, char *argv[])
{

    int number = 42;
    int *ptr1 =  NULL;
    int **ptr2 =  NULL;

    ptr1 = &number;
    ptr2 = &ptr1;

    /* All should print 42 */
    fprintf(stdout, "number\t= %d\n", number);
    fprintf(stdout, "*ptr1\t= %d\n", *ptr1);
    fprintf(stdout, "**ptr2\t= %d\n", **ptr2);

    /*
     * **ptr2 == number
     * *ptr2 == &number
     * ptr2 == &ptr1
     */
    fprintf(stdout, "\n");
    fprintf(stdout, "**ptr2\t= %d\n", **ptr2);
    fprintf(stdout, "*ptr2\t= %p (&number)\n", *ptr2);
    fprintf(stdout, "ptr2\t= %p (&ptr1)\n", ptr2);

    fprintf(stdout, "\n");
    fprintf(stdout, "&number\t= %p\n", &number);
    fprintf(stdout, "&ptr1\t= %p\n", &ptr1);
}



