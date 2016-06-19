#include <stdio.h>
#define DO_TWICE(X) { X; X; }

int main(int argc, char *argv[])
{

    DO_TWICE(fprintf(stdout, "Twice.\n"));
    /* fprintf(stdout, "Twice.\n"); fprintf(stdout, "Twice.\n"); */

return 0;
}


