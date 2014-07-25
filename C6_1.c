#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int l, *arr = NULL;
    void sort(int *, int);
    int i;

    printf("The length of the array-> ");
    scanf("%d", &l);
    arr = (int *)malloc(l * sizeof(int));
    for (i = 0; i < l; i++)
    {
        scanf("%d", arr + i);
    }
    sort(arr, l - 1);

    for (i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}

void sort(int *arr, int r)
{
    int i, j;
    for (i = 1; i <= r; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                arr[j - 1] ^= arr[j];
                arr[j] ^= arr[j - 1];
                arr[j - 1] ^= arr[j];
            }
        }
    }
}