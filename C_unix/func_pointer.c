/*
 * func_pointer.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>

void *my_func(void *args)
{
  printf("%s: %s LINE = %d\n", __FILE__, __FUNCTION__, __LINE__);
}

int main(int argc, char *arg[])
{

  void *(*my_funcPtr)(void *);

  my_funcPtr = &my_func;
  my_funcPtr(NULL);

}

