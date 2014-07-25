#include <stdio.h>
#include <time.h>
#define N 6
#define M 10

int main(void)
{
    int a[N] = {3, 5, 0, 3, 1, 4};
    int i;
    void discount(int*);

    discount(a);
    for (i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

void discount(int *a)
{
    int i, j, cnt[M], b[M];
    for (j = 0; j < M; j++) cnt[j] = 0;
    for (i = 0; i < N; i++) cnt[a[i]+1]++;
    for (j = 1; j < M; j++) cnt[j] += cnt[j-1];
    for (i = 0; i < N; i++)
    {
        b[cnt[a[i]]] = a[i];
        cnt[a[i]]++;
    }
    for (i = 0; i < N; i++) a[i] = b[i];
    return;
}