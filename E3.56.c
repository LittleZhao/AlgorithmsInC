#include <stdio.h>
#include <stdlib.h>
#define N 20

int main(void)
{
    char *str = NULL;
    int len;
    void char_count(char *);

    str = (char *)malloc(N*sizeof(char));
    printf("Please input a string less than %d charaters\n", N);

    scanf("%s", str);

    char_count(str);

    free(str);
    str = NULL;
    return 0;

}

void char_count(char *str)
{
    char num[256] = {0};
    int i;

    for (i=0; str[i]!='\0'; i++)
    {
        num[str[i]] += 1;
    }

    for (i=0; i<256; i++)
    {
        if (num[i] > 0)
        {
            printf("%c: %d\n", i, num[i]);
        }
    }
    return;
}