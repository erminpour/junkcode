
/*
 * stack.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>

/* if(condition) ? do this when true : do this when false; */ 

#define STACK_SIZE          2
#define STACK_FULL()        (SP == STACK_SIZE)
#define STACK_EMPTY()       (SP == 0)
#define STACK_PUSH(VAR)     (STACK[SP++] = VAR)
#define STACK_POP()         (STACK[--SP])

static unsigned int SP = 0;
static unsigned short STACK[STACK_SIZE];

int main(int argc, char *argv[])
{

    short int var1 = 1;
    short int var2 = 42;
    short int var3 = 3;

    if (! STACK_FULL())
        STACK_PUSH(var1);

    if (! STACK_FULL())
        STACK_PUSH(var2);

    if (! STACK_FULL())
        STACK_PUSH(var3);

    if (!STACK_EMPTY())
        fprintf(stdout, "Poping stack: %d\n", STACK_POP());
    if (!STACK_EMPTY())
        fprintf(stdout, "Poping stack: %d\n", STACK_POP());
    if (!STACK_EMPTY())
        fprintf(stdout, "Poping stack: %d\n", STACK_POP());

return 0;
}

