
#include <stdio.h>

//int val[] __attribute__ ((section(".text"))) = {1, 2, 3, 4, 5 ,6};
int val[] __attribute__ ((section(".text#"))) = {1, 2, 3, 4, 5 ,6};

int getval(int i)
{
    return val[i];
}

int main(int argc, char *argv[])
{
    fprintf(stdout, "%d\n", getval(1));
return 0;
}

