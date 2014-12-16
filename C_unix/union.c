
#include <stdio.h>

//#define CPU_PC_START 0x200
#define CPU_PC_START 0xDEAD
typedef unsigned char byte; /* A single byte of memory */

/* A word is two bytes. By using a union, you can
 * access either the low or high byte of the word
 * as a separate entity.
 */
typedef union {
    unsigned short int WORD;
    struct {
    #ifdef WORDS_BIGENDIAN
        byte high, low;
    #else
        byte low, high;
    #endif
    } BYTE;
} word;

int
main(int argc, char *argv[])
{
    word pc;
    pc.WORD = CPU_PC_START;
    printf("0x%02X\n", pc.WORD);
    printf("0x%02X\n", pc.BYTE);
    #ifdef WORDS_BIGENDIAN
    printf("0x%X%02X\n", pc.BYTE.high, pc.BYTE.low);
    #else
    printf("0x%X%02X\n", pc.BYTE.low, pc.BYTE.high);
    #endif

return 0;
}



