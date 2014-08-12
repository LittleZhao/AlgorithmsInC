#include <stdio.h>
#include "Point.h"
int main(void)
{
    point a, b, c;
    int i, r;

    printf("Please input the coordinate of three points\n");
    scanf("%lf %lf", &(a.x), &(a.y));
    scanf("%lf %lf", &(b.x), &(b.y));
    scanf("%lf %lf", &(c.x), &(c.y));

    r = oneLine(a, b, c);

    if (r == 1)
    {
        printf("These three points are in one line\n");
    }
    else
    {
        printf("NoNoNo\n");
    }
    return 0;
}