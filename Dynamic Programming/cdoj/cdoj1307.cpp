#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int dp[10][12],dig[10];
int dfs(int pos,int num,int fg)
{
    int lst=num?num%10:11;
    //判断是否是首位，lst=11的话，下面的判断windy数都可通过
    if(pos<0) return 1; //搜完
    if(fg&&~dp[pos][lst]) return dp[pos][lst];  //搜过的，直接返回
    int ans=0,lim=fg?9:dig[pos];
    //fg = 1时，证明前面的位已小于最大值，后面的位可随意变，所以这时lim = 9
    for( int i=0;i<=lim;i++ )
    {
        if(lst-i<2&&i-lst<2) continue;  //是否满足windy数
        ans+=dfs(pos-1,num*10+i,fg||i<lim);
        // fg || i<lim 是为了判断现在的数位是否已小于最大值
    }
    return fg?dp[pos][lst]=ans:ans;
    //dp[i][j]是i+1位的数字中，首位为j的数字能形成windy数的个数
}

int cal(int x)
{
    if(x==0) return 1;
    int i=0;
    for(;x;x/=10) dig[i++]=x%10;
    return dfs(i-1,0,0);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int a,b;
    while(cin>>a>>b)
    {
        printf("%d\n",cal(b)-cal(a-1));
    }
    return 0;
}
