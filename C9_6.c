//priority queue based on heap
//command: cc C9_6.c C9_5.c C9_5.h
#include <stdio.h>
#include <time.h>
#include "C9_5.h"
#define L 10

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
