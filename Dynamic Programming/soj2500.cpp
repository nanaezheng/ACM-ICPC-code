#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define PF(x) (scanf("%d",&x))
#define PT(x,y) (scanf("%d%d",&x,&y))
#define PR(x) (printf("%d\n",x))
#define PRT(x,y)(printf("%d %d\n",x,y))
#define M 1005
int n;
int arr[M];
int ar[M];
int a[M];
int maxx(int a,int b)
{
	return a>b?a:b;
}
int minx(int a,int b)
{
	return a>b?b:a;
}
void init()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(ar,0,sizeof(ar));
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
			PF(a[i]);

		ar[0] = 1;
		arr[n-1] = 1;
		for(int i=1;i<n;i++)
		{
			ar[i]=1;
			for(int j=0;j<i;j++)
				if(a[i]>a[j]) ar[i] = maxx(ar[i],ar[j]+1);
		}
		for(int i=n-2;i>=0;i--)
		{
			arr[i]=1;
			for(int j=n-1;j>i;j--)
				if(a[i]>a[j]) arr[i] = maxx(arr[i],arr[j]+1);
		}
		int ans = 0x7fffffff;
		if(n>2)
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
			{
				if(i==j) ans = minx(ans,n-(ar[i]+arr[i]-1));
				else
				{
					ans = minx(ans,j-i-1+i+1-ar[i]+n-j-arr[j]);
				}
			}
		else ans = 0;
		PR(ans);
	}
	return ;
}
int main()
{
	init();
	return 0;
}
