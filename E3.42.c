//list insertion without head node
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6

typedef struct node *link;

struct node {
    int data;
    link next;
};

int main(void)
{
    struct node head_a;
    link a;
    int i;

    void list_print(link);
    link insertion_sort(link);


    srand((unsigned)time(NULL));
    a = &head_a;

    for (i=0; i<N; i++)
    {
        a->next = (link)malloc(sizeof(head_a));
        a = a->next;
        a->data = rand() % 60;
        a->next = NULL;
    }

    list_print(head_a.next);

    a = insertion_sort(head_a.next);

    list_print(a);
    return 0;
}

link insertion_sort(link f)
{
    link t, i, j, k;

    t = f;
    i = f->next;
    t->next = NULL;

    for (; i!=NULL; i=j)
    {
        j = i->next;

        if (i->data < t->data)//without head point, need more operation for the head
        {
            i->next = t;
            t = i;
        }
        else
        {
            for (k=t; NULL!=k->next; k=k->next)
            {
                if (k->next->data > i->data)
                {
                    break;
                }
            }
            i->next = k->next;
            k->next = i;
        }
    }
    return t;
}


void list_print(link a)
{
    link l = a;
    while (NULL != l)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
    return;
}