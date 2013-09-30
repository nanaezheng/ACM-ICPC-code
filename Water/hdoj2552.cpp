#include <stdio.h>
#include <math.h>
#define pi 3.14159246
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        double s, u;
        scanf("%lf %lf",&s, &u);
        double sum = atan(1.0/s) - atan(1.0/u);
        double v = 1.0 / tan(sum);
        double anwer = v * u - s * u - s * v;
        printf("%.0lf\n",anwer);
    }
    return 0;
}
