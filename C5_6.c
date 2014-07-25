#include <stdio.h>
#include <stdlib.h>

int max(int *, int, int);

int main(void)
{
    int l, *a, i;
    printf("The number of the array-> ");

    scanf("%d", &l);
    a = (int *)malloc(l * sizeof(int));

    for (i = 0; i < l; i++)
    {
        scanf("%d", a + i);
    }

    i = max(a, 0, l);
    printf("The max is %d", i);
    return 0;
}

int max(int *a, int l, int r)
{
    int m = (l + r) / 2;
    int u, v;

    if (l == r)
    {
        return a[l];
    }

    u = max(a, l, m);
    v = max(a, m + 1, r);

    if (u >= v)
    {
        return u;
    }
    else
    {
        return v;
    }
}