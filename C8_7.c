//merge sort list
#include <stdio.h>
#include <stdlib.h>
#define N 5
#include <time.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))

typedef struct node* link;

struct node
{
    /* data */
    int data;
    link next;
};

link mergesort(link);
link merge(link, link);

int main(void)
{
    struct node head;
    link m = &head;
    int i;

    srand((unsigned) time(NULL));
    m->next = NULL;

    for (i=0; i<N; i++)
    {
        m->next = (link)malloc(sizeof(head));
        m->next->data = rand() % 20;
        printf("%d ", m->next->data);
        m = m->next;
        m->next = NULL;
    }

    printf("\n");

    m = head.next;

    m = mergesort(m);

    for (i=0; i<N && NULL != m; i++)
    {
        printf("%d ", m->data);
        m = m->next;
    }


    return 0;
}

link mergesort(link m)
{
    link a, b;
    if (m == NULL || m->next == NULL)
    {
        return m;
    }
    a = m;
    b = m->next;

    while (NULL != b && NULL != b->next)
    {
        m = m->next;
        b = b->next;
    }
    m->next = NULL;

    return merge(mergesort(a), mergesort(b));
}

link merge(link a, link b)
{
    struct node head;
    link c = &head;

    while (NULL != a && NULL != b)
    {
        if (a->data < b->data)
        {
            c->next = a;
            c = a;
            a = a->next;
        }
        else
        {
            c->next = b;
            c = b;
            b = b->next;
        }
    }
    if (NULL == a)
    {
        c->next = b;
    }
    else
    {
        c->next = a;
    }
    return(head.next);
}