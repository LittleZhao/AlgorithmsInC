//heap sort, from large to small
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define exch(A, B) {int t=(A);(A)=(B);(B)=t;}
#define L 10

void heapsort(int *, int);
void fixDown(int *, int, int);

int main(void)
{
    int *arr = NULL, i;
    srand((unsigned) time(NULL));

    arr = (int *)malloc((L+1)*sizeof(int));

    for (i=1; i<=L; i++)
    {
        arr[i] = rand() % 50;
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapsort(arr, L);

    for (i=1; i<=L; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}

void heapsort(int *arr, int l)
{
    int k;

    for (k=l/2; k>0; k--)
    {
        fixDown(arr, k, l);
    }

    while (l>1)
    {
        arr[1] ^= arr[l];
        arr[l] ^= arr[1];
        arr[1] ^= arr[l];
        l--;
        fixDown(arr, 1, l);
    }
    return;
}

void fixDown(int *arr, int f, int t)
{
    int i;
    while (2*f<=t)
    {
        i = 2 * f;
        //if ((i<t) && (arr[i]<arr[i+1]))
        if ((i<t) && (arr[i]>arr[i+1]))
        {
            i += 1;
        }

        //if (arr[f]>=arr[i])
        if (arr[f]<=arr[i])
        {
            break;
        }

        exch(arr[f], arr[i]);
        f = i;
    }
    return;

}