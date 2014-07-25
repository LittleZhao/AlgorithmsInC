//select the Nth number
#include <stdio.h>

int main(void)
{
    int a[6] = {5, 2, 9 ,0, 1, 3};

    void select(int *, int, int, int);
    int partition(int *, int, int);

    select(a, 0, 5, 3);

    printf("%d\n", a[3]);
    return 0;
}

void select(int *a, int l, int r, int k)
{
    int i = -1;
    while (r > l && i != k)
    {
        i = partition(a, l, r);
        if (i >= k)
        {
            r = i-1;
        }

        if (i <= k)
        {
            l = i+1;
        }

    }
}

int partition(int *a, int l, int r)
{
    int i = l-1;
    int j = r;
    int v = a[r];

    while (1)
    {
        while (a[++i] < v);

        while (a[--j] > v)
        {
            if (j == l)
            {
                break;
            }
        }

        if (i >= j)
        {
            break;
        }

        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
    }

    if (i < r)
    {
        a[i] ^= a[r];
        a[r] ^= a[i];
        a[i] ^= a[r];
    }
    return i;
}