
#include <stdio.h>
#include <sys/prctl.h>

int main(int argc, char *argv[])
{
    prctl(PR_SET_NAME, "<-----pRoCeSs");
    for(;;);

return 0;
}

