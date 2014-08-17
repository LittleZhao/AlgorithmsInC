//use arry to make up a list, and solve josephus function
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N, M, *f=NULL;
    int i, j;

    N = atoi(argv[1]);
    M = atoi(argv[2]);

    f = (int *)malloc((N+1)*sizeof(int));

    for (i=1; i<=N; i++)
    {
        if (i < N)
        {
            f[i] = i + 1;
        }
        else
        {
            f[i] = 1;
        }

    }

    for (i=N; i!=f[i];)
    {
        for (j=1; j<M; j++)
        {
            i=f[i];
        }
        printf("%d ", f[i]);
        f[i] = f[f[i]];
    }

    printf("\nThe last one is %d\n", i);
    free(f);
    f = NULL;
    return 0;
}