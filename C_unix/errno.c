
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{

    /* write to unopened file descriptor */
    int var = 0;
    write(42, &var, sizeof(var));

    /* print errno and strerror(ernno) values */
    fprintf(stderr, "errno = %d: %s \n",errno,strerror(errno));

return 0;
}

