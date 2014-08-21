#include <stdlib.h>
#include "STACK.h"

static int *s;
static int N;

void STACKinit(maxN)
{
    s = (int *)malloc(maxN * sizeof(int));
    N = 0;
}

int STACKempty()
{
    return N==0;
}

void STACKpush(int data)
{
    s[N] = data;
    N++;
}

int STACKpop()
{
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
}
