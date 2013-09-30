#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 10105
char a[N],b[N];
int f[N][N];
int arr[1005];
int dp[1000];
int n;
double ar[N];
//int a[N];
double bb[N];

int LCS(char a[],char b[])
{
    int i,j,len1,len2;
    len1=(int)strlen(a);
    len2=(int)strlen(b);
    for(i=1; i<=len1; i++)
        for(j=1; j<=len2; j++)
        {
            if(a[i-1]==b[j-1])
                f[i][j]=f[i-1][j-1]+1;
            else
                f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    return f[len1][len2];
}

/*

int LIS(int *arr, int n)
{
    for(int i=1; i<=n; ++i)
        dp[i] = 0;
    int ans;
    dp[1] = 1;
    for(int i=2; i<=n; ++i)
    {
        ans = dp[i];
        for(int j=1; j<i; ++j)
        {
            if(arr[i]>arr[j] && dp[j]>ans)
                ans = dp[j];
        }
        dp[i] = ans+1;
    }
    ans = 0;
    for(int i=1; i<=n; ++i)
    {
        if(dp[i] > ans)
            ans = dp[i];
    }
    return ans;
}
*/
/*
int maxsum()
{
    int dig[10100];
    for(int i=0; i<n; i++)
        scanf("%d",&dig[i]);
    int num=0;
    for(int i=0; i<n; i++)
        if(dig[i]<0)
            num++;
    if(num==n)
        cout<<0<<" "<<dig[0]<<" "<<dig[n-1]<<endl;
    else
    {
        int start=0,end=0,max=-9999,sum=0;
        for(int i=0,k=0; i<n; i++)
        {
            sum+=dig[i];
            if(sum>max)
            {
                max=sum;
                start=k;
                end=i;
            }
            if(sum<0)
            {
                sum=0;
                k=i+1;
            }
        }
        cout<<max<<" "<<dig[start]<<" "<<dig[end]<<endl;
    }
}
*/


double maxx(double as,double bs)
{
	return as>bs?as:bs;
}


int bag01()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		for(int i=0;i<m;i++)
			scanf("%d%lf",&a[i],&b[i]);
		memset(ar,0.0,sizeof(ar));

		for(int i=0;i<m;i++)
		{
			for(int j=n;j>=a[i];j--)
				ar[j] = maxx(1.0 - (1-ar[j-a[i]])*(1-b[i]),ar[j]);
		}
		ar[n]*=100;
		printf("%.1lf%%\n",ar[n]);

	}
}
int main()
{

    while(cin>>a>>b)
        cout<<LCS(a,b)<<endl;

    /*LIS
    while(cin>>n)
    {
        for(int i=1; i<=n; ++i)
            cin>>arr[i];
        cout <<LIS(arr, n)<<endl;
    }
    */
    /*maxsum
    while(cin>>n)
    {
        if(n==0)break;
        maxsum();
    }
    */

    //bag01();

    return 0;
}
