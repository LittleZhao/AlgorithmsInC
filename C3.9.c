//Josephus function
#include <stdlib.h>
#include <stdio.h>
typedef struct node* link;
struct node
{
    /* data */
    int data;
    link next;
};

int main(int argc, char *argv[])
{
    int N, M;
    link new, x;
    struct node head;
    int i;

    N = atoi(argv[1]);
    M = atoi(argv[2]);
    head.data = 1;
    head.next = &head;
    x = &head;

    for (i=2; i<=N; i++)
    {
        new = (link)malloc(sizeof(head));
        new->data = i;
        new->next = NULL;
        x->next = new;
        x = new;
    }
    x->next = &head;

    while (x != x->next)
    {
        for (i=1; i<M; i++)
        {
            x = x->next;
        }
        printf("%d ", x->next->data);
        x->next = x->next->next;
    }

    printf("\nThe final one is %d\n", x->data);

    return 0;
}