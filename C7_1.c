//quick_sort
#include <stdio.h>
#include <time.h>
#define N 6

int main(void)
{
    int a[N];
    int i;
    void quick_sort(int *, int, int);
    int partition(int *, int, int);

    srand((unsigned) time(NULL));

    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 20;
        printf("%d ", a[i]);
    }
    printf("\n");

    quick_sort(a, 0, N-1);

    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void quick_sort(int *a, int l, int r)
{
    int i;
    if (l >= r)
    {
        return;
    }
    i = partition(a, l, r);
    quick_sort(a, l, i-1);
    quick_sort(a, i+1, r);
}

int partition(int *a, int l, int r)
{
    int i = l - 1;
    int j = r;
    int v = a[r];

    while (1)
    {
        while ((a[++i] < v));
        while ((a[--j] > v))
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
