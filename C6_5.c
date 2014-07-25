//shell sort
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int l, *arr = NULL;
    void shell_sort(int *, int, int);
    int i;
    printf("The length of the array->");
    scanf("%d", &l);
    arr = (int *)malloc(l * sizeof(int));
    for (i = 0; i < l; i++)
    {
        scanf("%d", arr + i);
    }


    shell_sort(arr, 0, l - 1);

    for (i = 0; i < l; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);
    arr = NULL;

    return 0;
}

void shell_sort(int *arr, int l, int r)
{
    int i, j, h, temp;
    for (h = l; h <= (r - l)/9; h = 3*h+1);

    for (; h > 0; h /= 3)
    {
        for (i = l + h; i <= r; i++)
        {
            j = i;
            temp = arr[i];

            while ((j >= l + h) && (arr[j - h] > temp))
            {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = temp;
        }
    }

}