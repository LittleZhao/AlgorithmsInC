// cc C4.3.c stack.c STACK.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STACK.h"

int main(int argc, char *argv[])
{
    char *e = argv[1];
    char *output = NULL;
    char temp;
    int i, j, len, k=0;

    len = strlen(e);
    STACKinit(len/2);
    output = (char *)malloc(len * sizeof(char));

    for (i=0; i<len; i++)
    {

        if (e[i] == ')')
        {
            temp = STACKpop();
            printf(" %c ", temp);
            output[k++] = ' ';
            output[k++] = temp;
            output[k++] = ' ';
        }

        if (e[i]=='+' || e[i] == '-' || e[i] == '*' || e[i] == '/')
        {
            printf(" ");
            output[k++] = ' ';
            STACKpush(e[i]);
        }

        if (e[i]>='0' && e[i]<='9')
        {
            printf("%c", e[i]);
            output[k++] = e[i];
        }
    }
    STACKfree();
    printf("\n");
    for (i=0; i<k; i++)
    {
        printf("%c", output[i]);
    }

    free(output);
    output = NULL;

    return 0;

}