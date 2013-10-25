#include<stdio.h>
#include<string.h>
int n,m;
int f[2010],weight[2010],cost[2010];
int max(int x,int y)
{
    return x>y?x:y;
}
int zeroonepack(int cost,int weight)
{
    int i;
    for(i=m;i>=cost;i--)
        f[i]=max(f[i],f[i-cost]+weight);
    return f[n];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        int i;
        for(i=1;i<=n;i++)
            scanf("%d",&weight[i]);
        for(i=1;i<=n;i++)
            scanf("%d",&cost[i]);
        memset(f,0,sizeof(f));//这一步一定不可少
        for(i=1;i<=n;i++)
            zeroonepack(cost[i],weight[i]);
        printf("%d\n",f[m]);
    }
    return 0;
}
