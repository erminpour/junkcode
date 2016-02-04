
#include <stdio.h>
#include <unistd.h>

void main(void)
{
    /* sleep() == seconds */
    int rc = sleep(10);
    if (rc != 0)
    {
        printf("sleep() interrupted with %d seconds left.\n", rc);
    }

    /* usleep() == microseconds */
    if(usleep(1000))
    {
        perror("usleep()");
    }
}

