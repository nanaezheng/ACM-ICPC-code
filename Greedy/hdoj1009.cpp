#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*----------------------*Global Variable*----------------------*/
int F[1001],J[1001],M,N;
double bl[1001];
//*=======================*Main Program*=======================*//
using namespace std;

int main()
{
    //freopen("input","r",stdin);
    while(scanf("%d%d",&M,&N)!=EOF&&M!=-1&&N!=-1)
    {
        for(int i=0; i<N; ++i)
        {
            scanf("%d%d",J+i,F+i);
            bl[i]=1.0*J[i]/F[i];
        }
        for(int i=0; i<N; ++i) //冒泡吧,数据不大
        {
            for(int j=N-1; j>i; --j)
            {
                if(bl[j]>bl[j-1])
                {
                    swap(bl[j],bl[j-1]);
                    swap(J[j],J[j-1]);
                    swap(F[j],F[j-1]);
                }
            }
        }
        double res=0;
        int p=0;
        while(M&&p<N)
        {
            if(M>=F[p])
            {
                res+=J[p];
                M-=F[p];
                p++;
            }
            else
            {
                res+=bl[p]*M;
                M=0;
            }
        }
        printf("%.3lf\n",res);
    }
    return 0;
}
