#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 6
int main(void)
{
    int a[N];
    int i;
    int max(int *, int, int);

    srand((unsigned) time(NULL));

    for (i=0; i<N; i++)
    {
        a[i] = rand() % 30;
        printf("%d ", a[i]);
    }
    printf("\n");

    i = max(a, 1, N-1);
    printf("i is %d\n", i);

    if (i < a[0])
    {
        printf("%d\n", a[0]);
    }
    else
    {
        printf("%d\n", i);
    }
    return 0;
}

int max(int *a, int f, int t)
{
    int m = f + (t-f)/2;
    int u, v;
    if (f == t)
    {
        return a[f];
    }

    u = max(a, f, m);
    v = max(a, m+1, t);
    if (u > v)
    {
        return u;
    }
    else
    {
        return v;
    }
}
