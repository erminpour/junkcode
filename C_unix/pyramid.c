#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(int argc, char *argv[])
{

int loop1, loop2;

/* Print half square */
fprintf(stdout, "\nHalf-square %dx%d:\n", SIZE, SIZE);
for (loop1=0; loop1 < SIZE; loop1++)
{
    for (loop2=0; loop2 < SIZE; loop2++)
    {
        if (loop2 <= loop1)
            fprintf(stdout, "X");
    }
    fprintf(stdout, "\n");
}
fprintf(stdout, "\n");

/* Print full square */
fprintf(stdout, "Full-square %dx%d:\n", SIZE, SIZE);
for (loop1=0; loop1 < SIZE; loop1++)
{
    for (loop2=0; loop2 < SIZE; loop2++)
    {
        fprintf(stdout, "X");
    }
    fprintf(stdout, "\n");
}
fprintf(stdout, "\n");

return 0;
}

