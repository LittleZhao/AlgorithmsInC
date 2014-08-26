#include <stdlib.h>
#include <stdio.h>
#include "STACK.h"

static int *s;
static int N;
static int LEN;

void STACKinit(maxN)
{
    if (NULL != s)
    {
        STACKfree();
    }
    s = (int *)malloc(maxN * sizeof(int));
    N = 0;
    LEN = maxN;
}

int STACKempty()
{
    return N==0;
}

void STACKpush(int data)
{
    if (N == LEN)
    {
        STACKerror(1);
    }
    s[N] = data;
    N++;
}

int STACKpop()
{
    //E4.20
    if (0 == N)
    {
        STACKerror(0);
    }
    N--;
    return s[N];
}

void STACKfree()
{
    if (NULL != s)
    {
        free(s);
        s = NULL;
    }
    N = 0;
    LEN = 0;
}

//E4.21
void STACKerror(int type)
{
    if (0 == type)
    {
        printf("The stack is empty, cannot pop anything.\n");
        exit(1);
    }
    if (1 == type)
    {
        printf("The stack is full, cannot push anything.\n");
        exit (1);
    }
}
