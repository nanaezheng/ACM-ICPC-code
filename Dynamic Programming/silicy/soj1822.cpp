// Problem#: 1822
// Submission#: 1920933
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 100
using namespace std;

int dp[100][100];
int a[100][100];
int i,j,k,h,len,n;
int input()
{
    cin>>n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            cin>>a[i][j];
    memset(dp,0,sizeof(dp));
    for(i=0; i<2*n-1; i++)dp[i][i+1]=1;
}
int solve()
{
    for(len=2; len<=n; len++)//枚举区间
        for(i=0; i+len<2*n;i++) //枚举起点
        {
            j=len+i;
            for(k=i+1; k<j; k++)//枚举中间值k
                if(dp[i][k]&&dp[k][j]&&(a[i<n?i:i-n][k<n?k:k-n]||a[j<n?j:j-n][k<n?k:k-n]))dp[i][j]=1;
        }
    for(i=0; i<n; i++)
        if(dp[i][i+n])cout<<1<<endl;
        else cout<<0<<endl;
        cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
