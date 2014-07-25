//list bubble sort
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5


typedef struct node* link;
struct node
{
    /* data */
    int data;
    link next;
};

int main(void)
{
    struct node head_a, head_b;
    void init_list(link);
    void print_list(link);
    void bubble_sort(link);
    void destroy(link);

    link a = &head_a;
    init_list(a);
    print_list(a->next);

    bubble_sort(a);
    print_list(a->next);

    destroy(a);

    return 0;
}

void bubble_sort(link head)
{
    link tag, i, j, tail = NULL;


    while (NULL != head->next && tail != head->next->next)
    {
        tag = head;

        while (tag->next->next != tail)
        {
            i = tag->next;
            j = i->next;
            if (i->data > j->data)
            {
                i->next = j->next;
                j->next = i;
                tag->next = j;
            }
            tag = tag->next;
        }
        tail = tag->next;
    }
}

void init_list(link h)
{
    link t;
    int i;
    srand((unsigned) time(NULL));
    //printf("Please enter %d randon number\n", N);
    for (i = 0, t = h; i < N; i++)
    {
        t->next = (link)malloc(sizeof(*t));
        t = t->next;
        //scanf("%d", &(t->data));
        t->data = rand() % 50;
        t->next = NULL;
    }
    return;
}

void print_list(link h)
{
    while (NULL != h)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
    return;
}

void destroy(link n)
{
    link t = NULL;
    while (NULL != n)
    {
        t = n->next;
        free(n);
        n = t;
    }
    return;
}
