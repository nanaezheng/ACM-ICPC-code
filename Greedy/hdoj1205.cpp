#include<iostream>
#include <cstdlib>
#include<string.h>
#include <stack>
#include<stdio.h>
#define MAX 500005
using namespace std;

int dp[MAX],poor[MAX];

int main()
{
    int i,j,k,h=0,r,l,mark,n,m,maxx;
    while(scanf("%d",&n)==1)
    {
        maxx=0;
        h++;
        if (n==0)
        {
            printf("Case %d:\nMy king, at most 0 road can be built.\n\n",h);
            continue;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&k,&l);
            poor[k]=l;
        }
        memset(dp,0,sizeof(dp));
        int len=1;
        dp[1]=poor[1];
        for(i=2; i<=n; i++)
        {
            l=0;
            r=len;
            int mid=(1+len)/2;
            while (r>=l)
            {
                if(poor[i]>dp[mid])
                    l=mid+1;
                else
                    r=mid-1;
                mid=(l+r)/2;
            }
            if (l>len)
            {
                len++;
                dp[l]=poor[i];
            }
            else
                dp[l]=dp[l]<poor[i]?dp[l]:poor[i];
        }
        if(len>1)
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n",h,len);
        else
            printf("Case %d:\nMy king, at most %d road can be built.\n\n",h,len);
    }
}

