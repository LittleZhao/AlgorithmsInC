#include <stdio.h>
#define N 101

int main(void)
{
    int i, j, p[N] = {0};

    for (i=2; i<N; i++)
    {
        if (0 == p[i])
        {
            for (j=i; i*j<N; j++)
            {
                p[i*j] = 1;
            }
        }
    }

    for (i=2; i<N; i++)
    {
        if (0 == p[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;

}