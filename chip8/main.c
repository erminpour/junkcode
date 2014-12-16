
/*
 * main.c
 * Chip8 Emulator
 * Victor Hugo Erminpour
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
    /* Initialize main memory */
    /* Allocate 4k on the heap for chip8 system memory. */
    if (!memory_init(MEM_4K))
    {
        fprintf (stderr, "ERROR: Unable to allocate main memory.\n");
        exit (1);
    }

  // Emulation loop
  //for(;;)
  //{
        // Emulate one cycle
        //myChip8.emulateCycle();
            
        // If the draw flag is set, update the screen
        // if(myChip8.drawFlag)
               // drawGraphics();

        // Store key press state (Press and Release)
               // myChip8.setKeys(); 
  //}

return 0;
}




