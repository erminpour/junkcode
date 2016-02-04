#include <stdio.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
    printf("\n");
}

int main(void)
{

    unsigned int foo = 10;
    bin(foo);
    foo = 1;
    bin(foo);

return 0;
}


