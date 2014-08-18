#include <stdio.h>
#include <stdlib.h>
#define N 20

int main(void)
{
    char *str = NULL;
    void check(char *);

    printf("Please input a string less than %d characters\n",N);
    str = (char *)malloc(N*sizeof(char));

    scanf("%s", str);

    check(str);
    return 0;

}

void check(char *str)
{
    int head, tail;

    for (tail=0; str[tail]!='\0'; tail++)
    {}

    for (head=0; head > tail;)
    {
        if (' ' == str[head])
        {
            head++;
            continue;
        }

        if (' ' == str[tail])
        {
            tail--;
            continue;
        }

        if (str[head] == str[tail])
        {
            head++;
            tail--;
            continue;
        }

        if (str[head] != str[tail])
        {
            printf("No\n");
            return;
        }
    }

    printf("Yes");
    return;

}