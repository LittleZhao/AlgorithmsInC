// selection sort in list
#include <stdio.h>
#include <stdlib.h>

typedef struct node* link;

struct node
{
    int data;
    link next;
};

int main(void)
{
    struct node head;
    link out = NULL;
    int l;

    link init(int);
    link list_selection(link);
    void show(link);

    printf("How many items->");
    scanf("%d", &l);
    head.next = init(l);
    show(head.next);
    out = list_selection(&head);
    show(out);
    return 0;
}

link init(int l)
{
    struct node h;
    link t = &h;
    for (; l > 0; l--)
    {
        t->next = (link)malloc(sizeof *t);
        t = t->next;
        t->next = NULL;
        scanf("%d", &(t->data));
    }
    return (h.next);

}

link list_selection(link h)
{
    link max = NULL, t = NULL, out = NULL;
    link findmax(link);
    while (h->next != NULL)
    {
        max = findmax(h);
        t = max->next;
        max->next = t->next;
        t->next = out;
        out = t;
    }
    return (out);
}

link findmax(link h)
{
    int m;
    link p = h->next;
    link t = h;

    m = p->data;

    while (NULL != p->next)
    {
        if (p->next->data > m)
        {
            t = p;
            m = p->next->data;
        }
        p = p->next;
    }
    return t;
}

void show(link p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}