
/*
 * fizzbuzz.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int idx = 0;

  for(idx = 1; idx <= 100; idx++)
  {
    if((idx%3) == 0)
      fprintf(stdout,"Fizz");

    if((idx%5) == 0)
      fprintf(stdout, "Buzz");

    if((idx%3) > 0 && ((idx%5) > 0))
      fprintf(stdout, "%d", idx);

    fprintf(stdout,"\n");
  }
}

