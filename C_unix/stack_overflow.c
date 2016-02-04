
#include <stdio.h>

void killStack(void)
{
  killStack();
}

int main(int argc, char *argv[])
{
    fprintf(stdout, "kIlL sTaCk\n");
    killStack();

return 0;
}

