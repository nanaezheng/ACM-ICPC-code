#include<iostream>
#include<cmath>
using namespace std;

int re[40000];
void bigplus(int n)
{
    int i,flag=0;
    for(i=1;i<=re[0];i++)
    {
        re[i]=re[i]*n+flag;
        if(re[i]>99999){
            flag=re[i]/100000;
            re[i]%=100000;
        }
        else flag=0;
    }
    if(flag){ re[i]=flag;re[0]++;}
}

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF){
        memset(re,0,sizeof(re));
        re[0]=1;re[1]=1;
        for(i=2;i<=n;i++)
            bigplus(i);
        printf("%d",re[re[0]]);
        for(i=re[0]-1;i>=1;i--)
            printf("%05d",re[i]);
        printf("\n");
    }
    return 0;
}
