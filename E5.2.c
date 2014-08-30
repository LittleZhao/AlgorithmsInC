#include <stdio.h>
int cal(int, int);
int main(void)
{
    int n, m, r;

    printf("Now we will calculate (N! mod M)\n");
    printf("N = ");
    scanf("%d", &n);
    printf("M = ");
    scanf("%d", &m);

    r = cal(n, m);
    printf("%d\n", r);
    return 0;
}

int cal(n, m)
{
    if (n == 1)
    {
        return 1;
    }

    return ((cal(n-1, m) * (n%m))%m);
}