#include <stdio.h>

#define min(A, B) ((A) < (B)) ? (A) : (B)

int main(void)
{
    int a[6] = {9, 0, 2, 7, 1, 5};
    void merge(int*, int, int, int);
    void mergesortBU(int*, int, int);
    int i;

    mergesortBU(a, 0, 5);

    for (i=0; i<6; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void mergesortBU(int* a, int l, int r)
{
    int i, m;
    for (m=1; m<=r-l; m=m+m)
    {
        for (i=l; i<=r-m; i+=m+m)
    }
}