//do not finish
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
typedef struct node* link;

struct node
{
    /* data */
    int data;
    link next;
};

void link_quick_sort(link, link);
link partition(link, link);

int main(void)
{
    struct node head;
    link p = &head;
    int i;

    srand((unsigned) time(NULL));

    for (i=0; i<N; i++)
    {
        p->next = (link)malloc(sizeof(head));
        p->next->data = rand() % 15;
        p = p->next;
        printf("%d ", p->data);
        p->next = NULL;
    }
    printf("\n");

    link_quick_sort(head.next, p);

    p = head.next;

    for (p = head.next; p!=NULL; p=p->next)
    {
        printf("%d ", p->data);
    }
    return;

}

void link_quick_sort(link l, link r)
{
    link i=NULL, n=NULL, front=NULL, behind=NULL, flag=NULL, head=NULL;

    if (l == r || r->next == l)
    {
        return;
    }

    i = l->next;
    n = i->next;

    behind = l;
    flag = r->next;

    l->next = flag;
    while (i != flag)
    {
        if (l->data > i->data)
        {
            i->next = l;
            if (NULL != front)
            {
                front->next = i;
                front = i;
            }
            else
            {
                front = i;
                head = i;
            }
        }
        else
        {
            i->next = behind->next;
            behind->next = i;
            behind = i;
        }
        i = n;
        n = i->next;
    }

    if (NULL == front && NULL == head)
    {
        front = head = l;
    }

    link_quick_sort(head, front);
    link_quick_sort(l->next, behind);
    return;
}

link partition(link l, link r)
{
    link i=NULL, n=NULL, front=NULL, behind=NULL, tail=NULL;

    i = l->next;
    n = i->next;

    behind = l;
    tail = r->next;

    l->next = r->next;
    while (i != tail)
    {
        if (l->data > i->data)
        {
            i->next = l;
            if (NULL != front)
            {
                front->next = i;
                front = i;
            }
            else
            {
                front = i;
            }
        }
        else
        {
            i->next = behind->next;
            behind->next = i;
            behind = i;
        }
        i = n;
        n = i->next;
    }
    return l;
}