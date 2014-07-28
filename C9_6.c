//priority queue based on heap
#include <stdio.h>
#include <time.h>
#include "C9_5.h"
#define L 5

extern int *pq;
extern int N;

int main(void)
{
    int i, value;

    PQinit(L);
    srand((unsigned) time(NULL));

    for (i=0; i<L; i++)
    {
        value = rand() % 20;
        printf("%d ", value);
        PQinsert(value);
    }
    printf("\n");

    for (i=0; i<L; i++)
    {
        printf("%d ", PQdelmax());
    }
    printf("\n");

    PQdestroy();
    return 0;
}
