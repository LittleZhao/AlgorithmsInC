//ternary tree heap sort, from large to small
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define exch(A, B) {int t=(A);(A)=(B);(B)=t;}
#define N 10


void heapSort(int *, int);
void fixDown(int *, int, int);

int main(void)
{
    int *arr = NULL, i;
    srand((unsigned) time(NULL));

    arr = (int *)malloc((N+1)*sizeof(int));

    for (i=1; i<=N; i++)
    {
        arr[i] = rand() % 50;
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, N);

    for (i=1; i<=N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}

void heapSort(int *arr, int l)
{
    int r;
    for (r=(l+1)/3; r>0; r--)
    {
        fixDown(arr, r, l);
    }

    while (l>1)
    {
        exch(arr[1], arr[l]);
        l--;
        fixDown(arr, 1, l);
    }
    return;
}

void fixDown(int *arr, int f, int t)
{
    int i, j, flag;
    while (3*f-1 <= t)
    {
        // the children's index of f are 3f-1, 3f, 3f+1
        i = flag = 3*f-1;
        for (j=2; j>0; j--)
        {
            if (i+1<=t)
            {
                if (arr[flag]>arr[i+1])
                {
                    flag = i+1;
                }
                i += 1;
            }
        }
        if (arr[f] <= arr[flag])
        {
            break;
        }

        exch(arr[f], arr[flag]);
        f = flag;
    }
    return;
}
