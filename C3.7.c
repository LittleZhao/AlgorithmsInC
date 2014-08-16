#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int *f=NULL, N, M, cnt;
    int i, j;

    int my_atoi(char *);
    int heads();

    if (argc != 3)
    {
        printf("Please input two arguments\n");
        exit(1);
    }
    srand((unsigned)time(NULL));

    N = my_atoi(argv[1]);
    M = my_atoi(argv[2]);

    //printf("N=%d, M=%d\n", N, M);

    f=(int *)malloc((N+1)*sizeof(int));

    for (i=0; i<=N; i++)
    {
        f[i] = 0;
    }

    for (i=0; i<M; i++, f[cnt]++)
    {
        for (j=0, cnt=0; j<N; j++)
        {
            if (heads())
            {
                cnt++;
            }
        }
    }

    for (i=0; i<=N; i++)
    {
        printf("%d:", i);

        for (j=10; j<=f[i]; j+=10)
        {
            printf(" *");
        }
        printf("\n");
    }
    /*for (i=0; i<=N; i++)
    {
        printf("%d: %d\n", i, f[i]);
    }*/

    free(f);
    f = NULL;

    return 0;
}

int my_atoi(char *str)
{
    int i, num=0;
    if (str == NULL)
    {
        printf("No input!\n");
        exit(1);
    }

    for (i=0, num=0; str[i]!='\0' && str[i]>='0' && str[i]<='9'; i++)
    {
        num = num*10 + (str[i] - '0');
    }
    return num;
}

int heads()
{
    return rand() > RAND_MAX / 2;
}