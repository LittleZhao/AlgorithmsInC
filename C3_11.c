//list insertion sort
#include <stdio.h>
#include <stdlib.h>
#define N 15

typedef struct node* link;

struct node
{
    int data;
    link next;
};

int main(void)
{
    struct node head_a, head_b;
    link a = &head_a;
    link b = &head_b;
    head_b.next = NULL;
    link temp = NULL;
    void list_print(link);
    void destroy(link);
    void insertion_sort(link,link);

    int i;

    for (i = 0, temp = a; i < N; i++)
    {
        temp->next = (link)malloc(sizeof(*temp));
        temp = temp->next;
        temp->data = rand() % 20;
        temp->next = NULL;
    }
    temp = NULL;
    list_print(a->next);

    insertion_sort(a, b);

    list_print(b->next);

    destroy(a->next);
    destroy(b->next);
    return 0;

}

void insertion_sort(link a, link b)
{
    link i = NULL;
    link j = NULL;

    while (NULL != a->next)
    {
        i = a->next;
        j = b;
        while ((NULL != j->next) && (j->next->data < i->data))
        {
            j = j->next;
        }

        a->next = i->next;
        i->next = j->next;
        j->next = i;
    }
    return;
}

void list_print(link h)
{
    while (NULL != h)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
    return;
}

void destroy(link h)
{
    link t = NULL;
    while (NULL != h)
    {
        t = h->next;
        free(h);
        h = t;
    }
    return;
}