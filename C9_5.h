#include <stdio.h>
#include <stdlib.h>
#define exch(A, B) {int t=(A);(A)=(B);(B)=t;}
static int *pq;
static int N;

void PQint(int);
int PQempty();
void PQinsert(int);
int PQdelmax();
void fixUp(int *, int);
void fixDown(int *, int, int);

void PQint(int maxN)
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
    pq[++N] = v;
    fixUp(pq, N);
}

int PQdelmax()
{
    exch(pq[N], pq[1]);
    fixDown(pq, 1, N-1);
    return pq[N--];
}

void fixUp(int *q, int n)
{
    while (n/2>0 && (q[n/2]>q[n]))
    {
        exch(q[n/2], q[n]);
        n /= 2;
    }
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
