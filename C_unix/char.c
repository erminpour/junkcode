
#include <stdio.h>

void main(void)
{
    char foo = 'A';
    printf("%d %c\n", foo, foo);

    /* int constants */
    int hex = 0x10;     /* base-10 16 */
    int octal = 012;    /* base-10 10 */
    printf("hex = %d\noctal = %d\n", hex, octal);

}

