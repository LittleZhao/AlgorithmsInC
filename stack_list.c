#include <stdlib.h>
#include "STACK.h"

typedef struct STACKnode *link;

struct STACKnode
{
    int data;
    link next;
};

static link head;

void STACKinit(int maxN)
{
    head = NULL;
}

int STACKempty()
{
    return NULL==head;
}

link NEW(int value, link next)
{
    link new = (link)malloc(sizeof(*new));
    new->data = value;
    new->next = next;
    return new;
}

void STACKpush(int value)
{
    head = NEW(value, head);
}

int STACKpop()
{
    int r = head->data;
    link t = head->next;
    free(head);
    head = t;
    return r;
}

