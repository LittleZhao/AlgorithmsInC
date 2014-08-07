#include <stdio.h>
#define N 10

int main(void)
{
    int id[N], sz[N], p, q, pr, qr;
    int i;

    for (i=0; i<N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }

    printf("Please insert two ids to connect each other, the id should be less than %d\n", i);

    while (scanf("%d %d", &p, &q)==2 && (p>=0 && q>=0))
    {
        if ((p>=N) || (q>=N))
        {
            printf("Invalid connection pair!!!\n");
            continue;
        }
        for (pr=p; pr!=id[pr]; pr=id[pr])
        {
            id[pr] = id[id[pr]];
        }

        id[p] = pr;

        for (qr=q; qr!=id[qr]; qr=id[qr])
        {
            id[qr] = id[id[qr]];
        }

        id[q] = qr;

        if (sz[pr] > sz[qr])
        {
            id[qr] = pr;
            sz[pr] += sz[qr];
        }
        else
        {
            id[pr] = qr;
            sz[qr] += sz[pr];
        }
    }

    //verify the result
    printf("The result is:\n");
    for (i=0; i<N; i++)
    {
        printf("%d:%d\n", i, id[i]);
    }

    return 0;
}