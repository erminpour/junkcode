
/*
 * dirent.c
 * Victor Hugo Erminpour
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{

    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
    {
        fprintf(stderr, "ERROR: usage: %s <dir>\n", argv[0]);
        exit(1);
    }

    if((dp = opendir(argv[1])) == NULL)
    {
        fprintf(stderr, "ERROR: Cannot open %s\n", argv[1]);
        exit(1);
    }

    while((dirp = readdir(dp)) != NULL)
        fprintf(stdout, "%s\n", dirp->d_name);

    closedir(dp);

return 0;
}

