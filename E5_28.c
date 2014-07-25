#include <stdio.h>

int tail_zero(int, int);

int main(void)
{
    int n, r;
    printf("enter a positive number-> ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("We only need positive number!!!");
        return 0;
    }

    if (n % 2 == 1)
    {
        printf("There are 0 tail zero\n");
    }
    else
    {
        r = tail_zero(n, 0);
        printf("there are %d tail zero\n", r);
        //printf("%d\n", n & 01);
    }
    return 0;
}

int tail_zero(int n, int count)
{
    if (n & 01 == 1)
    {
        return count;
    }

    n = n >> 1;
    //printf("Now n is %d\n", n);
    count += 1;
    return tail_zero(n, count);
}