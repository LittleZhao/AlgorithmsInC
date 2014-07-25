//insertion_sort stable
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, *arr = NULL;
    void insertion_sort(int *, int);
    int i;

    printf("The length of the array-> ");
    scanf("%d", &l);
    arr = (int *)malloc(l * sizeof(int));
    for (i = 0; i < l; i++)
    {
        scanf("%d", arr + i);
    }
    insertion_sort(arr, l - 1);

    for (i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}

void insertion_sort(int *arr, int r)
{
    int i, j, k;
    for (i = 1; i <= r; i++)
    {
        k = arr[i];
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > k)
            {
                arr[j] = arr[j - 1];
            }
            else
            {
                break;
            }
        }
        arr[j] = k;
    }
}