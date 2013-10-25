#include <stdio.h>
#include <math.h>
void main()
{
    double n,m,sum,k;
    int i,j;
    while (scanf ("%lf%lf",&m,&n)!=EOF)
    {
        sum=0;
        k=sqrt(m);
        for (i=1;i<n;i++)
        {    sum=sum+k;
            k=sqrt(k);}
        sum=sum+m;
        printf ("%.2lf\n",sum);
    }
}
