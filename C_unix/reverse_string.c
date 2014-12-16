
/*
 * reverse_string.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>

/* Recursive reverse string */
void reverse_string(char *str)
{
  if(*str)
  {
    reverse_string(str +1);
    putchar(*str);
  }
}

int main(int argc, char *argv[])
{

  reverse_string("Hello");
  putchar('\n');
  reverse_string(argv[0]);
  putchar('\n');

return 0;
}

