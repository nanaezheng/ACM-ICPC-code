#include <stdio.h>
#include <iostream>
using namespace std;

int map[15][15];
int cst[11]={1,2,4,8,16,32,64,128,256,512,1024};
int dp[1200];
int Max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int n,i,j,k,ans;
	while(1)
	{
		cin>>n;
		if (n==0) break;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for (i=0;i<cst[n];i++)
		{
			dp[i]=0;
		}
		for (i=0;i<cst[n];i++)
		{
			for (j=0;j<n;j++)
			{
				if ((i & cst[j])!=0) continue;
				for (k=0;k<n;k++)
				{
					if ((i & cst[k])==0 && j!=k)
					{
						dp[i|cst[j]]=Max(dp[i|cst[j]],dp[i]+map[k][j]);
					}
				}
			}
		}
		ans=0;
		for (i=0;i<cst[n];i++)
		{
			if (dp[i]>ans) ans=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
