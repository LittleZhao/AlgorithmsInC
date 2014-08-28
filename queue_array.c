#include <stdlib.h>
#include <stdio.h>
#include "QUEUE.h"

static int head, tail, N, *q, count;

void QUEUEinit(int maxN)
{
    q = (int *)malloc(N * sizeof(maxN+1));
    N = maxN; //in my opinion, the book is wrong, we just need q[0] to q[maxN-1] to store data,
    head = N; //we will never put or get data from q[N];
    tail = 0;
    count = 0;
}

int QUEUEempty()
{
    return head%N == tail;
}

//E4.32
static void QUEUEerror(int t)
{
    if (0 == t)
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
    if (count == N)
    {
        QUEUEerror(0);
        return;
    }

    q[tail++] = value;  //tail's value is the position of next input data
    tail %= N;
    count++;
    return;
}

int QUEUEget()
{
    if (0 == count)
    {
        QUEUEerror(1);
        exit(1);
    }
    head %= N;
    count--;
    return q[head++];  //head's value is the position of next output data.
}

