/*
 * memory.h
 * Chip8 Emulator
 * Victor Hugo Erminpour
 */
 
#ifndef __MEMORY_H__
#define __MEMORY_H__

/* Chip8 Memory Map
 * 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
 * 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
 * 0x200-0xFFF - Program ROM and work RAM
 */
#define MEM_4K 0x1000       /* 4K memory size. */
#define SP_START 0x52       /* Start of the system stack. */
#define ROM_DEFAULT 0x200   /* Default ROM load point. */

typedef unsigned char byte; /* A single byte of memory */
byte *memory;

/*
 * A word is 2 bytes. Using a union, access
 * the high or low BYTE or the entire WORD.
 * The size of the union is 2 bytes.
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

/* memory.c */
int memory_init(int size);
void memory_destroy(void);
inline void memory_write(register word address, register byte value);
inline byte memory_read(register int address);

#endif

