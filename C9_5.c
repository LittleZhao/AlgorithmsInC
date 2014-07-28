#include "C9_5.h"
#include <stdlib.h>
#include <stdio.h>
#define exch(A, B) {int t=(A);(A)=(B);(B)=t;}


void PQinit(int maxN)
{
    pq = (int *)malloc((maxN+1)*sizeof(int));
    N = 0;
}

int PQempty()
{
    return N==0;
}

void PQinsert(int v)
{
    ++N;
    pq[N] = v;
    fixUp(pq, N);
}

void fixUp(int *q, int n)
{
    while (n/2>0 && (q[n/2]<q[n]))
    {
        exch(q[n/2], q[n]);
        n /= 2;
    }
}

int PQdelmax()
{
    exch(pq[N], pq[1]);
    fixDown(pq, 1, N-1);
    N--;
    return pq[N+1];

}

void PQdestroy()
{
    free(pq);
    pq = NULL;
    N = 0;
    return;
}



void fixDown(int *q, int f, int t)
{
    int j;
    while (2*f<=t)
    {
        j = 2 * f;
        if (j<t && (q[j]<q[j+1]))
        {
            j += 1;
        }

        if (q[f] >= q[j])
        {
            break;
        }

        exch(q[f], q[j]);
        f = j;
    }
}