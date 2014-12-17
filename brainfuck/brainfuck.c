
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

#include <stdio.h>

/* < > + - , . [ ] */
/* > : increment data pointer */
/* < : decrement data pointer */
/* + : increment data cell */
/* - : decrement data cell */
/* . : output character from data cell */
/* , : input character to data cell */
/* [ : jump intruction pointer forward */
/* ] : jump instructon pointer back */

#define OPCODE_INC_DP       1
#define OPCODE_DEC_DP       2
#define OPCODE_INC_VAL      3
#define OPCODE_DEC_VAL      4
#define OPCODE_OUT          5
#define OPCODE_IN           6
#define OPCODE_JMP_FWD      7
#define OPCODE_JMP_BCK      8
#define OPCODE_END          0

#define PROGRAM_SIZE    4096    /* 4k */
#define DATA_SIZE       65536   /* 64k */

struct bf_opcode
{
    unsigned short opcode;
    unsigned short operand;
};

static struct bf_opcode PROGRAM[PROGRAM_SIZE];
unsigned short int DATA[DATA_SIZE];

/* Stack for jumps */
#define STACK_SIZE          1024 /* 1k stack */
#define STACK_FULL()        (SP == STACK_SIZE)
#define STACK_EMPTY()       (SP == 0)
#define STACK_PUSH(VAR)     (STACK[SP++] = VAR)
#define STACK_POP()         (STACK[--SP])

static unsigned int SP = 0;
static unsigned short STACK[STACK_SIZE];

/* Prototypes */
int parse_bfcode(FILE *);
void execute_bfcode(void);

int main(int argc, char *argv[])
{
    int rc;
    FILE *filep;

    /* open file */
    if (argc != 2 || (filep = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return -1;
    }

    /* parse bfcode */
    parse_bfcode(filep);

    /* close file */
    fclose(filep);

    /* execute bfcode */
    execute_bfcode();

return 0;
}

int parse_bfcode(FILE *filep)
{
    unsigned short int pc = 0, jump_pc;
    int c;

    while ((c = getc(filep)) != EOF && pc < PROGRAM_SIZE)
    {
        switch (c)
        {
        case '<':
            PROGRAM[pc].opcode = OPCODE_DEC_DP;
            break;
        case '>':
            PROGRAM[pc].opcode = OPCODE_INC_DP;
            break;
        case '+':
            PROGRAM[pc].opcode = OPCODE_INC_VAL;
            break;
        case '-':
            PROGRAM[pc].opcode = OPCODE_DEC_VAL;
            break;
        case ',':
            PROGRAM[pc].opcode = OPCODE_IN;
            break;
        case '.':
            PROGRAM[pc].opcode = OPCODE_OUT;
            break;
        case '[':
            PROGRAM[pc].opcode = OPCODE_JMP_FWD;
            if (! STACK_FULL())
                STACK_PUSH(pc);
            break;
        case ']':
            if (!STACK_EMPTY())
                jump_pc = STACK_POP();
            PROGRAM[pc].opcode = OPCODE_JMP_BCK;
            PROGRAM[pc].operand = jump_pc;
            PROGRAM[jump_pc].operand = pc;
            break;
        default:
            pc--;
            break;
        }
    pc++;
    }

    if (!STACK_EMPTY() || pc == PROGRAM_SIZE)
        return -1;

    PROGRAM[pc].opcode = OPCODE_END;
    return 0;
}

void execute_bfcode(void)
{
    unsigned short pc = 0;
    unsigned int data_ptr = DATA_SIZE;

    /* initialize data cells to zero */
    while (--data_ptr)
        DATA[data_ptr] = 0;

    while (PROGRAM[pc].opcode != OPCODE_END && data_ptr < DATA_SIZE)
    {
        switch (PROGRAM[pc].opcode)
        {
            case OPCODE_DEC_DP:
                data_ptr--;
                break;
            case OPCODE_INC_DP:
                data_ptr++;
                break;
            case OPCODE_INC_VAL:
                DATA[data_ptr]++;
                break;
            case OPCODE_DEC_VAL:
                DATA[data_ptr]--;
                break;
            case OPCODE_OUT:
                putchar(DATA[data_ptr]);
                break;
            case OPCODE_IN:
                DATA[data_ptr] = (unsigned int) getchar();
                break;
            case OPCODE_JMP_FWD:
                if(!DATA[data_ptr])
                    pc = PROGRAM[pc].operand;
                break;
            case OPCODE_JMP_BCK:
                if(DATA[data_ptr])
                    pc = PROGRAM[pc].operand;
                break;
            default:
                break;
        }
    pc++;
    }
}

