#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 5
int *pq;
int N;
int MAX;

void PQint(int maxN)
{
    pq = (int*)malloc(maxN * sizeof(int));
    MAX = maxN;
    N = 0;
    return;
}

int PQempty()
{
    return N == 0;
}

int PQinsert(int v)
{
    int i, n;

    if (N == MAX)
    {
        return 0;
    }
    N++;
    pq[N] = v;
    for (i=N; i>0; i--)
    {
        if (pq[i-1] > v)
        {
            pq[i] = pq[i-1];
        }
        else
        {

            break;
        }
    }
    pq[i] = v;
    return 1;
}

int PQdelmax()
{
    int out;
    out = pq[N];
    N--;
    return out;
}

void PQprint()
{
    int i;
    for (i=0; i<N; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int i;
    srand((unsigned) time(NULL));
    PQint(L);
    for (i=0; i<L; i++)
    {
        PQinsert(rand()%20);
        PQprint();
    }
    return 0;
}
