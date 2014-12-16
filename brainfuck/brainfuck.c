
/*
 * brainfuck.c
 * Brainf*ck Emulator/Interpreter
 * Victor Hugo Erminpour
 */

/*
 * A Turing complete esoteric programming
 * language created by Urban Müller, based on 
 * P'' by Corrado Böhm.
 */

/* < > + - , . [ ] */
/*
 * <    -
 * >    -
 * +    -
 * -    -
 * ,    -
 * .    -
 * [    -
 * ]    -
 */

#include <stdio.h>

int compile_bfcode(FILE *);
int execute_bfcode(void);

int main(int argc, char *argv[])
{
    int rc;
    FILE *filep;

    /* Parse cmndline for input tape */

    /* open file */
    /* compile bfcode */
    compile_bfcode(filep);

    /* execute bfcode */

return 0;
}

int compile_bfcode(FILE *filep)
{

}

int execute_bfcode(void)
{

}


