//selection sort, unstable
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, *arr = NULL;
    void selection_sort(int *, int, int);
    int i;

    printf("The length of the array->");
    scanf("%d", &l);
    arr = (int *)malloc(l * sizeof(int));
    for (i = 0; i < l; i++)
    {
        scanf("%d", arr + i);
    }

    selection_sort(arr, 0, l - 1);

    for (i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}

void selection_sort(int *arr, int l, int r)
{
    int min_tag, i, j;

    for (i = l; i < r; i++)
    {
        min_tag = i;
        for (j = i + 1; j <= r; j++)
        {
            if (arr[j] < arr[min_tag])
            {
                min_tag = j;
            }
        }

        if (min_tag != i)
        {
            arr[min_tag] ^= arr[i];
            arr[i] ^= arr[min_tag];
            arr[min_tag] ^= arr[i];
        }
    }
}