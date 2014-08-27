#include <stdlib.h>
#include "QUEUE.h"

static int head, tail, N, *q;

void QUEUEinit(int maxN)
{
    N = maxN + 1;   //we will never put or get data from q[N];
    q = (int *)malloc(N * sizeof(int));
    head = N;
    tail = 0;
}

int QUEUEempty()
{
    return head%N == tail;
}

void QUEUEput(int value)
{
    q[tail++] = value;  //tail's value is the position of next input data
    tail %= N;
}

int QUEUEget()
{
    head %= N;
    return q[head++];  //head's value is the position of next output data.

}