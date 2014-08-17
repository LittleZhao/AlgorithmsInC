//reverse a list
#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct node *link;
struct node
{
    /* data */
    int data;
    link next;
};

int main(void)
{
    struct node head;
    link x;
    int i, j;
    link reverse(link);

    x = &head;

    printf("Please input %d numbers to build the list\n", N);

    for (i=0; i<N; i++)
    {
        x->next = (link)malloc(sizeof(head));
        x = x->next;
        scanf("%d", &(x->data));
        x->next = NULL;
    }

    x = reverse(head.next);

    for (i=0; i<N; i++)
    {
        printf("%d ", x->data);
        x = x->next;
    }
    return 0;
}


link reverse(link x)
{
    link p, n;
    p = n = NULL;
    while (NULL != x)
    {
        n = x->next;
        x->next = p;
        p = x;
        x = n;
    }

    return p;
}