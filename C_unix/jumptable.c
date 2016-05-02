
/*
 * jumptable.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>

void foo_func(void)
{
    fprintf(stdout, "%s\n", __FUNCTION__);
}

void bar_func(void)
{
    fprintf(stdout, "%s\n", __FUNCTION__);
}

void baz_func(void)
{
    fprintf(stdout, "%s\n", __FUNCTION__);
}

typedef void (*Handler)(void);
Handler jump_table[] = { foo_func, bar_func };

int main(int argc, char *argv[])
{

    jump_table[0]();
    jump_table[1]();
    jump_table[1] = baz_func;
    jump_table[1]();

return 0;
}

