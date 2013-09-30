#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int M=100010;
typedef long long ll;
int n,c,rec[M];
ll low[M],high[M],dp[2][102];

int main()
{
   while(~scanf("%d%d",&n,&c))
   {
      memset(dp,0x3f,sizeof(dp));
      for(int i=1;i<=n;i++)
         scanf("%d",&rec[i]);
      for(int i=rec[1];i<=100;i++)
         dp[1][i]=(i-rec[1])*(i-rec[1]);
      low[0]=dp[1][0];
      for(int j=1;j<=100;j++)
         low[j]=min(low[j-1],dp[1][j]-c*j);
      high[100]=dp[1][100]+c*100;
      for(int j=99;j>=0;j--)
         high[j]=min(high[j+1],dp[1][j]+c*j);
      int e=1;
      for(int i=2;i<=n;i++)
      {
         e=1-e;
         memset(dp[e],0x3f,sizeof(dp[e]));
         for(int j=rec[i];j<=100;j++)
            dp[e][j]=min(low[j]+c*j,high[j]-c*j)+(j-rec[i])*(j-rec[i]);
         low[0]=dp[e][0];
         for(int j=1;j<=100;j++)
            low[j]=min(low[j-1],dp[e][j]-c*j);
         high[100]=dp[e][100]+c*100;
         for(int j=99;j>=0;j--)
            high[j]=min(high[j+1],dp[e][j]+c*j);
      }
      ll ans=99999999999999LL;
       for(int i=0;i<100;i++)
          ans=min(dp[e][i],ans);
       cout<<ans<<endl;
    }
    return 0;
}
