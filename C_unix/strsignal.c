
#define _GNU_SOURCE
#include <string.h>     /* strsignal() */
#include <stdio.h>
#include <signal.h>

extern const char * const sys_siglist[];

int main(int argc, char *argv[])
{

    int signum;
    for(signum = 1; (signum < NSIG); signum++)
    {
        fprintf(stdout, "Signal #%d == %s", signum, sys_siglist[signum]);
        fprintf(stdout, "\nSignal #%d == %s\n\n", signum, strsignal(signum));
    }

    fprintf(stdout, "SIGRTMIN = %d\nSIGRTMAX = %d\n\n", SIGRTMIN, SIGRTMAX);

return 0;
}


