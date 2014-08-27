#include <stalib.h>
#include "queue.h"

typedef struct QUEUEnode *link;

struct QUEUEnode
{
    /* data */
    int data;
    link next;
};

static link head, tail;

void QUEUEinit(int maxN)
{
    head = NULL;
}

int QUEUEempty()
{
    return NULL == head;
}

static link NEW(int v, link next)
{
    link n = (link)malloc(sizeof(*n));
    n->data = v;
    n->next = next;
    return n;
}

void QUEUEput(int value)
{
    if (NULL == head)
    {
        tail = NEW(value, head);
        head = tail;
    }
    else
    {
        tail->next = NEW(value, tail->next);
        tail = tail->next;
    }
    return;
}

int QUEUEget()
{
    int value = head->data;
    link t = head;
    head = head->next;
    free(t);
    return value;
}