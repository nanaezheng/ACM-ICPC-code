#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include <algorithm>
using namespace std;
#define MAXN 1000050
#define LL long long
int n;
LL C[MAXN],A[MAXN];

int main()
{

    while(cin>>n)
    {
        LL sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>A[i];
            sum+=A[i];
        }
        LL avg=sum/n;
        sum=0;
        for(int i=0; i<n-1; i++)
        {
            sum+=A[i];
            C[i]=sum-(i+1)*avg;
        }
        sort(C,C+n-1);
        LL x=C[(n-1)/2];
        LL ans=abs(x);
        for(int i=0; i<n-1; i++)
        {
            ans+=abs(x-C[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
