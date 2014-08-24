//cc C4.2.c stack.c STACK.h
// use "" to wrap the expression
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "STACK.h"
#define N 20
int main(int argc, char *argv[])
{
    char *e = NULL;
    int i, j, len, temp;
    STACKinit(argc-1);

    for (j=1; j<argc; j++)
    {
        e = argv[j];
        len = strlen(e);
        for (i=0; i<len; i++)
        {
            if (e[i] =='+')
            {
                STACKpush(STACKpop() + STACKpop());
            }

            if (e[i] == '-')
            {
                STACKpush((-1) * (STACKpop() - STACKpop()));
            }

            if (e[i] == '*')
            {
                STACKpush(STACKpop() * STACKpop());
            }

            if (e[i]>='0' && e[i]<='9')
            {
                temp = 0;
                while (e[i]>='0' && e[i]<='9')
                {
                    temp = temp*10 + (e[i]- '0');
                    i++;
                }
                STACKpush(temp);
            }

        }
    }

    printf("%d\n", STACKpop());
    STACKfree();
    free(e);
    e = NULL;
    return 0;
}