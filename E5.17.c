#include <stdio.h>
#include <stdlib.h>
#define N 6
typedef struct node *link;

struct node{
    int data;
    link next;
};

int main(void)
{
    struct node head;
    link t;
    int i;
    int max(link, int);

    srand((unsigned)time(NULL));

    head.next = NULL;
    t = &head;
    for (i=0; i<N; i++)
    {
        t->next = (link)malloc(sizeof(head));
        t = t->next;
        t->data = rand() % 30;
        printf("%d ", t->data);
        t->next = NULL;
    }
    printf("\n");

    i = max((head.next)->next, (head.next)->data);
    printf("%d\n", i);
    return 0;
}

int max(link t, int m)
{
    if (NULL != t)
    {
        m = t->data > m ? t->data : m;
        return max(t->next, m);
    }
    else
    {
        return m;
    }
}