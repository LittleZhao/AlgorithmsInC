#include <stdio.h>
#include <math.h>

double duishu(double);
int main(void)
{
    double n = 0.0;
    double result = 0.0;
    printf("The number is -> ");
    scanf("%lf", &n);
    //printf("You enter number is %lf", n);

    result = duishu(n + 0.0);
    printf("The result is %lf\n", result);
    return 0;
}


double duishu(double n)
{
    //printf("The n is %lf\n", n);
    if (n - 1 > 0.0)
    {
        //printf("%lf\n", log(n));
        return log10(n) + duishu(n - 1.0);
    }
    else
    {
        return 0;
    }

}