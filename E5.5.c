#include <stdio.h>

int main(void)
{
    int m,n;
    int temp;

    printf("Please input m and n to calculate their greatest common divisor\n");
    while (scanf("%d %d", &m, &n) == 2)
    {
        if (m < n)
        {
            m ^= n;
            n ^= m;
            m ^= n;
        }
        while (n > 0)
        {
            temp = m%n;
            m = n;
            n = temp;
        }

        printf("%d\n", m);
    }
    return 0;
}