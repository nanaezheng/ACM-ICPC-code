#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int dp[10][12],dig[10];
int dfs(int pos,int num,int fg)
{
    int lst=num?num%10:11;
    //�ж��Ƿ�����λ��lst=11�Ļ���������ж�windy������ͨ��
    if(pos<0) return 1; //����
    if(fg&&~dp[pos][lst]) return dp[pos][lst];  //�ѹ��ģ�ֱ�ӷ���
    int ans=0,lim=fg?9:dig[pos];
    //fg = 1ʱ��֤��ǰ���λ��С�����ֵ�������λ������䣬������ʱlim = 9
    for( int i=0;i<=lim;i++ )
    {
        if(lst-i<2&&i-lst<2) continue;  //�Ƿ�����windy��
        ans+=dfs(pos-1,num*10+i,fg||i<lim);
        // fg || i<lim ��Ϊ���ж����ڵ���λ�Ƿ���С�����ֵ
    }
    return fg?dp[pos][lst]=ans:ans;
    //dp[i][j]��i+1λ�������У���λΪj���������γ�windy���ĸ���
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
