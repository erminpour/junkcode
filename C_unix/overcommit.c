#include <stdio.h>
#include <stdlib.h>

#define ONEGIG     1 << 30

int main(int argc, char *argv[]) {
    printf("Before\n");
    int i = 0;
    while (malloc(ONEGIG)) {
        printf("Allocated %d GB\n", ++i);
    }
    sleep(10);
    printf("After\n");

    return 0;
}

