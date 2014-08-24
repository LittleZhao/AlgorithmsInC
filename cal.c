// cc cal.c stack.c STACK.h
//first change to Reverse Polish notation, then calculate.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STACK.h"
void cal(char *, int);
int main(int argc, char * argv[])
{
    char *s = argv[1];
    char *rpn = NULL;
    int i, j, k, len;
    char temp;

    len = strlen(s);
    rpn = (char *)malloc(2 * len * sizeof(char));

    STACKinit(len/3);//I think it is enough
    k = 0;

    for (i=0; i<len; i++)
    {
        if (s[i] == ')')
        {
            temp = STACKpop();
            printf(" %c ", temp);
            rpn[k++] = ' ';
            rpn[k++] = temp;
            rpn[k++] = ' ';
            continue;
        }

        if (s[i]=='+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            printf(" ");
            STACKpush(s[i]);
            rpn[k++] = ' ';
            continue;
        }

        if (s[i]>='0' && s[i]<='9')
        {
            printf("%c", s[i]);
            rpn[k++] = s[i];
        }
    }

    STACKfree();
    printf("\n");
    for (i=0; i<k; i++)
    {
        printf("%c", rpn[i]);
    }
    printf("\n");

    cal(rpn, k);
    free(rpn);
    rpn = NULL;
    return 0;
}

void cal(char *s, int len)
{
    int num;
    int i, a, b;
    STACKinit(len/3);

    for (i=0; i<len; i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        if (s[i] == '+')
        {
            STACKpush(STACKpop() + STACKpop());
        }
        if (s[i] == '*')
        {
            STACKpush(STACKpop() * STACKpop());
        }
        if (s[i] == '-')
        {
            STACKpush((-1) * (STACKpop() - STACKpop()));
        }
        if (s[i] == '/')
        {
            a = STACKpop();
            b = STACKpop();
            (b*1.0 / a);
        }

        if (s[i]>='0' && s[i]<='9')
        {
            STACKpush(0);
        }
        while (s[i]>='0' && s[i]<='9')
        {
            STACKpush(10*STACKpop() + (s[i]-'0'));
            i++;
        }

    }
    printf("The result is %d\n", STACKpop());
    STACKfree();
    return;
}