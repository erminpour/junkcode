
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "gccpoison.h"

/* 4k buffer */
#define BUFSIZE     4096
#define VERSION     "Simple Shell v0.1\n"

static char buffer[BUFSIZE];

void clean_exit(void)
{
    fputs("Goodbye!\n", stdout);
    exit(0);
}

void catch_sigint(int signum)
{
    fputs("\n", stdout);
    clean_exit();
}

void print_help(void)
{
    fputs(VERSION, stdout);
    fputs("Help Menu:\n", stdout);
    fputs("\tquit | exit \t\tExit Shell.\n", stdout);
    fputs("\thelp | ? \t\tShow help menu.\n", stdout);
}

int main(int argc, char argv[])
{
    fputs(VERSION, stdout);

    /* Setup SIGINT (Ctrl-C) signal disposition. */
    struct sigaction act;
    act.sa_handler = catch_sigint;
    sigaction(SIGINT, &act, NULL);

    for(;;)
    {
        fputs("shell>", stdout);
        fgets(buffer, BUFSIZE, stdin);
        if ((strncmp(buffer, "quit\n", BUFSIZE) == 0) || \
            (strncmp(buffer, "exit\n", BUFSIZE) == 0))
        {
            clean_exit();
        }
        else if ((strncmp(buffer, "?\n", BUFSIZE) == 0) || \
            (strncmp(buffer, "help\n", BUFSIZE) == 0))
        {
            print_help();
            fflush(stdout);
            continue;
        }
        else if (feof(stdin))
        {
            fputs("\n", stdout);
            clean_exit();
        }
        else
        {
            fputs("FOO", stdout);
            fputs(buffer, stdout);
            continue;
        }
    }
return 0;
}

