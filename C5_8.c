#include <stdio.h>

void rule(int, int, int);

int main(void)
{
    int i = 8, j = 3;
    rule(0, 8, 3);
    return 0;
}

void rule(int l, int r, int h)
{
    int m = (l + r) / 2;
    if (h > 0)
    {
        printf("%d:%d ", m, h);
        rule(l, m, h - 1);
        //printf("%d:%d ", m, h);
        rule(m, r, h - 1);
    }
}