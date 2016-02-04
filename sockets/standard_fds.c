
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    char *msg = "This is a test.\n";
    /* get length in bytes */
    int len = strlen(msg);
    /* write can be called from signal handler */
    write(STDERR_FILENO, msg, len);

    fprintf(stdout, "STDIN_FILENO (stdin) = %d\n", STDIN_FILENO);
    fprintf(stdout, "STDOUT_FILENO (stdout) = %d\n", STDOUT_FILENO);
    fprintf(stdout, "STDERR_FILENO (stderr) = %d\n", STDERR_FILENO);

return 0;
}


