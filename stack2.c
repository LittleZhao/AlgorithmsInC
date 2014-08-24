#include <stdlib.h>
#include "STACK2.h"

point STACKinit(int maxN)
{
    point s = (point)malloc(maxN * sizeof(*s));
    if (maxN >= 0)
    {
        s[0].len = 0;
    }
    return s;
}

void STACKpush(point s, int data)
{
    s[s[0].len].data = data;
    s[0].len += 1;
}

int STACKpop(point s)
{
    s[0].len -= 1;
    return s[s[0].len].data;
}

void STACKfree(point s)
{
    if (NULL != s)
    {
        free(s);
        s = NULL;
    }
}



