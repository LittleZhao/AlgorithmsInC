//weighted quick union
#include <stdio.h>
#define N 10
int main(void)
{
    int id[N], h[N], p, q, pr, qr, ph, qh;
    int i;

    for (i=0; i<N; i++)
    {
        id[i] = i;
        h[i] = 0;
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

        ph = qh = 0;

        for (pr=id[p]; pr!=id[pr]; pr=id[pr], ph++);
        for (qr=id[q]; qr!=id[qr]; qr=id[qr], qh++);

        if (h[pr] < ph)
        {
            h[pr] = ph;
        }

        if (h[qr] < qh)
        {
            h[qr] = qh;
        }

        if (pr == qr)
        {
            continue;
        }

        if (h[pr] > h[qr])
        {
            id[qr] = pr;
        }
        else
        {
            id[pr] = qr;
            if (h[pr] == h[qr])
            {
                h[qr]++;
            }
        }
    }

    printf("verify the connection\n");

    for (i=0; i<N; i++)
    {
        printf("%d: %d\n", i, id[i]);
    }

    return 0;
}