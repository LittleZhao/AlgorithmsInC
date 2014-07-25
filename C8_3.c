//merge_sort
#include <stdio.h>
int aux[6] = {0};
void merge(int *, int, int, int);
int main(void)
{
    int i;


    void merge_sort(int *, int, int);

    int a[6] = {9, 0, 2, 7, 1, 5};

    merge_sort(a, 0, 5);

    for (i=0; i<6; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

void merge_sort(int *a, int l, int r)
{
    //int m = (r+l)/2;
    //int f;

    int m = l + (r-l)/2;
    if (r <= l)
    {
        return;
    }

    merge_sort(a, l, m);
    merge_sort(a, m+1, r);
    merge(a, l, m, r);
}

void merge(int *a, int l, int m, int r)
{
    int i, j, k;
    for (i = m+1; i > l; --i)
    {
        aux[i-1] = a[i-1];
    }

    for (j = m; j < r; j++)
    {
        aux[r+m-j] = a[j+1];
    }

    for (k = l; k <= r; k++)
    {
        if (aux[j] < aux[i])
        {
            a[k] = aux[j];
            j--;
        }
        else
        {
            a[k] = aux[i];
            i++;
        }
    }
    return;
}

