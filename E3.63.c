#include <stdio.h>
#include <stdlib.h>
int **malloc2d(int r, int c)
{
    int i;
    int **t = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
    {
        t[i] = (int *)malloc(c * sizeof(int));
    }
    return t;
}
int ***malloc3d(int x, int y, int z)
{
    int i;
    int ***t = (int ***)malloc(x * sizeof(int **));

    for (i=0; i<y; i++)
    {
        t[i] = malloc2d(y, z);
    }
    return t;
}

int main(void)
{
    int i, j, k;

    int ***cube = NULL;

    cube = malloc3d(2, 2, 2);

    printf("Pleae input data for 2*2*2 cube\n");

    for (i=0; i<2; i++)
        for (j=0; j<2; j++)
            for (k=0; k<2; k++)
            {
                scanf("%d", &(cube[i][j][k]));
            }

    for (i=0; i<2; i++)
        for (j=0; j<2; j++)
            for (k=0; k<2; k++)
            {
                printf("%d ", cube[i][j][k]);
            }

    return 0;

}

