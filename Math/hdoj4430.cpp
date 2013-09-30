#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std ;
long long powLL(long long a,int b){
    long long res=1;
    for(int i=0;i<b;i++)
        res*=a;
    return res;
}
int main()
{
    long long n,r,k;
    while(cin>>n)
    {
        r=1;
        k=n-1;
        for(int i=2;i<=45;i++)
        {
            long long ll,rr,mm;
            ll=2;
            rr=(long long)pow(n,1.0/i);
            while(ll<=rr)
            {
                mm=(long long)(ll+rr)/2;
                long long ans=(mm-powLL(mm,i+1))/(1-mm);
                if(ans==n||ans==n-1)
                {
                    if(i*mm<r*k)
                    {
                        r=i;
                        k=mm;
                    }
                    break;
                }
                else if(ans>n)
                {
                    rr=mm-1;
                }
                else
                {
                    ll=mm+1;
                }
            }
        }
        cout<<r<<" "<<k<<endl;
    }
    return 0;
}
