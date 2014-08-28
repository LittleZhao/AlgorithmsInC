#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct QUEUEnode *link;

struct QUEUEnode
{
    /* data */
    int data;
    link next;
};

static link head, tail, N;

void QUEUEinit(int maxN)
{
    head = NULL;
    N = 0;
}

int QUEUEempty()
{
    return NULL == head;
}

static link NEW(int v, link next)
{
    link n = (link)malloc(sizeof(*n));
    if (NULL == n)
    {
        return NULL;
    }
    n->data = v;
    n->next = next;
    return n;
}

static void QUEUEerror(int t)
{
    if (0 == t) //hard to test
    {
        printf("Put fails, FULL\n");
        return;
    }

    if (1 == t)
    {
        printf("Get fails, EMPTY\n");
        return;
    }
    return;
}

void QUEUEput(int value)
{
    if (NULL == head)
    {
        tail = NEW(value, head);
        head = tail;
        if (NULL == head)
        {
            QUEUEerror(0);
            return;
        }

    }
    else
    {
        tail->next = NEW(value, tail->next);
        if (NULL == tail->next)
        {
            QUEUEerror(0);
            return;
        }
        tail = tail->next;
    }
    N++;
    return;
}

int QUEUEget()
{
    if (0 == N)
    {
        QUEUEerror(1);
        exit(1);
    }
    int value = head->data;
    link t = head;
    head = head->next;
    free(t);
    N--;
    return value;
}