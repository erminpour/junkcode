
/* c_array.c */
/* Victor Hugo Erminpour */
#include <stdio.h>
#include <stdlib.h>

int myArray1[10] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
int myArray2[10] = { 1, 2 }; // 1,2,0,0,0...Elements missing will be set to 0
int myArray3[10] = { 0 }; // all elements 0
static int myArray4[10]; // all elements 0
int array[1024] = {[0 ... 1023] = 5};

int main(int argc, char *argv[])
{

    int int_array[20] = {[0 ... 19] = 0}, count=0;
    int num_elements = (sizeof(int_array)/sizeof(int_array[0]));
    fprintf(stdout, "num_elements\t=\t%d\n", num_elements);
    fprintf(stdout, "sizeof(int_array)\t=\t%d\n", sizeof(int_array));
    fprintf(stdout, "sizeof(int_array[0])\t=\t%d\n", sizeof(int_array[0]));

    for (count=0; count < num_elements; count++)
    {
        int_array[count] = count;
        fprintf(stdout, "int_array[%d]\t=\t%d\n", count, int_array[count]); 
        fprintf(stdout, "*(int_array+%d)\t=\t%d\n", count, *(int_array+count)); 
        fprintf(stdout, "Virtual address of int_array[%d]\t=\t%p\n", count, &int_array[count]); 
        fprintf(stdout, "Virtual address of int_array[%d]\t=\t%p\n", count, &(*(int_array+count))); 
    }

return 0;
}


