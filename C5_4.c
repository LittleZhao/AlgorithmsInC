#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *a;
int i = 0;

int eval();
int main(void)
{
    int result,len;
    a = (char *)malloc(50 * sizeof(char));
    fgets(a, 49, stdin);
    printf("%s\n",a);
    len = strlen(a);
    a[len - 1] = '\0';
    result = eval();
    printf("%d\n", result);
    /*
    for (result = 0; a[result] != '\0'; result++)
    {
        printf("%c ", a[result]);
    }
    printf("\n%d\n", result);
    */

    free(a);
    a = NULL;
    return 0;
}

int eval()
{
    int x = 0;
    while (' ' == a[i])
    {
        i++;
    }
    if ('+' == a[i])
    {
        i++;
        return eval() + eval();
    }
    if ('*' == a[i])
    {
        i++;
        return eval() * eval();
    }
    while ((a[i] >= '0') && (a[i] <= '9'))
    {
        x = 10 * x + (a[i] - '0');
        i++;
    }
    return x;
}

