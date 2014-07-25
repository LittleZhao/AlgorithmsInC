#include <stdio.h>
int gcd(int, int);

int gcd_2(int, int);

int main(void)
{
    int m, n, r;

    scanf("%d %d", &m, &n);

    r = gcd(m, n);
    printf("First: %d\n", r);

    r = gcd_2(m, n);
    printf("Second: %d\n", r);

    return 0;
}

int gcd(m, n)
{
    if (n == 0)
    {
        return m;
    }
    gcd(n, m%n);
}

int gcd_2(m, n)
{
    int tmp = 0;
    while (n > 0)
    {
        tmp = m % n;
        m = n;
        n = tmp;
    }
    return m;
}

