#include "Point.h"

int oneLine(point a, point b, point c)
{
    double slopeA, slopeB;

    if (a.x - b.x > 0.0001)
    {
        slopeA = (a.y-b.y)/(a.x-b.x);
    }
    else
    {
        slopeA = 0.0;
    }

    if (a.x - c.x > 0.0001)
    {
        slopeB = (a.y-c.y)/(a.x-c.x);
    }
    else
    {
        slopeB = 0.0;
    }

    if (slopeA - slopeB > 0.0001 || slopeA - slopeB < -0.0001)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}