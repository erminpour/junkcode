
#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE   42

struct list {
    int var;
    struct list *next;
};

typedef struct list Node;

int main(int argc, char *argv[])
{

    Node *current, *head=NULL;
    int count = 0;

    for(count = 0; count < LIST_SIZE; count++)
    {
        current = (Node *)malloc(sizeof(Node));
        current->var = count;
        current->next = head;
        head = current;
    }

    //current = head;

    while (current)
    {
        fprintf(stdout, "current->var = %d\n", current->var);
        current = current->next;
    }

return 0;
}


