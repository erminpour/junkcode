
/*
 * graphics.c
 * Chip8 Emulator
 * Victor Hugo Erminpour
 */
#include <stdio.h>

/* chip8 graphics */
unsigned char Graphics[32][64];

void initialize_graphics(void)
{
    int j,k;
    for(j=0;j<32;j++)
        for(k=0;k<64;k++)
            Graphics[j][k] = 0x00;
}

void clear_display()
{
    system("clear");
    int x,y;
    for(y=0;y<32;y++)
    {
        for(x=0;x<64;x++)
        {
            Graphics[y][x]==0x00;
            printf("O");
        }
        printf("\n");
    }
}

void graphics_update()
{
    /* I'm a lazy bastard */
    system("clear");
    int x,y;
    for(y=0; y<32; y++)
    {
        for(x=0; x<64; x++)
        {
            if(Graphics[y][x] == 0x01)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

/*
int main(int argc, char *argv[])
{

    initialize_graphics();
    Graphics[30][32] = 0x01;
    Graphics[31][33] = 0x01;
    clear_display();
    graphics_update();

return 0;
}
*/


