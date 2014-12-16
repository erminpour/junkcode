/*
 * memory.c
 * Chip8 Emulator
 * Victor Hugo Erminpour
 */

#include <stdlib.h>
#include "memory.h"

int memory_init(int size)
{
    /* Allocate chip8 memory on heap */
    memory = (byte *) malloc((sizeof(byte) * size));
    return memory != NULL;
}

void memory_destroy(void)
{
    /* Free memory from heap. */
    free(memory);
}

inline void memory_write(register word address, register byte value)
{
    memory[address.WORD] = value;
}

inline byte memory_read(register int address)
{
    return memory[address];
}

