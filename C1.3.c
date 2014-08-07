//weighted quick union
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

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (p>=N || q>=N)
        {
            printf("invalid connection pair, please input again!\n");
            continue;
        }

        if (p == -1)
        {
            break;
        }

        for (pr=id[p]; pr!=id[pr]; pr=id[pr]);
        for (qr=id[q]; qr!=id[qr]; qr=id[qr]);

        if (pr == qr)
        {
            continue;
        }

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

    printf("Please insert the two ids you want to check-> ");

    while (scanf("%d %d", &p, &q) == 2)
    {
        if (p>=N || q>=N)
        {
            printf("Invalid pair, please input again!\n");
            continue;
        }

        if (p == -1)
        {
            break;
        }
        for (pr=id[p]; pr!=id[pr]; pr=id[pr]);
        for (qr=id[q]; qr!=id[qr]; qr=id[qr]);

        if (pr == qr)
        {
            printf("%d<->%d connect each other\n",p, q);
            continue;
        }
        else
        {
            printf("%d and %d do not connet with each other\n", p, q);
            continue;
        }
    }

    return 0;
}