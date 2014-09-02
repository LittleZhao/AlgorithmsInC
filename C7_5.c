#include <stdio.h>
#include <time.h>
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {int t=A;A=B;B=t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define eq(A, B) (!less(A, B) && !less(B, A))
#define N 6

int main(void)
{
    int a[N];
    int i;

    void quick_sort(int *, int, int);

    srand((unsigned) time(NULL));
    for (i = 0; i<N; i++)
    {
        a[i] = rand() % 5;
        printf("%d ", a[i]);
    }
    printf("\n");

    quick_sort(a, 0, N - 1);

    for (i=0; i<N; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

void quick_sort(int *a, int l, int r)
{
    int i, j, k, p, q, v;
    if (r <= l)
    {
        return;
    }
    v = a[r];
    i = p = l-1;
    j = q = r;

    while (1)
    {
        while (less(a[++i], v));
        while (less(v, a[--j]))
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
        exch(a[i], a[j]);
        if (eq(a[i], v))
        {
            p++;
            exch(a[i], a[p]);
        }

        if (eq(a[j], v))
        {
            q--;
            exch(a[j], a[q]);
        }
    }
    exch(a[i], a[r]);
    j = i -1;
    i = i + 1;

    for (k=l; k<=p; k++, j--)
    {
        if (a[k] == a[j])
        {
            continue;
        }
        exch(a[k], a[j]);
    }
    for (k=r-1; k>=q; k--, i++)
    {
        if (a[k] == a[i])
        {
            continue;
        }
        exch(a[k], a[i]);
    }

    quick_sort(a, l, j);
    quick_sort(a, i, r);
}
