// Problem#: 1293
// Submission#: 1922877
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<stdio.h>

using namespace std;
long long  a;
int solve(long long  n)
{

    long long  sum=0;
    while(n>=1)
    {
        sum++;
        if(n==1)break;
        if(n%2==1)
            n=3*n+1;
        else
            n=n/2;
    }
    return sum;
}
int main()
{
    long long  i,a,b,h[1000000],maxx,hh;
    while(cin>>a>>b)
    {
        for(i=a; i<=b; i++)
        h[i]=solve(i);

    maxx = h[a];
    for(long long  j, i = a; i <=b; i++)
    {
        if(h[i] >maxx)
        {
            maxx = h[i];
            j = i;
        }
    }
    cout<<maxx<<endl;
    }
    return 0;
}
