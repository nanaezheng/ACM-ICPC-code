// Problem#: 4312
// Submission#: 1922951
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include <math.h>
#include<iomanip>
using namespace std;
int a[10000],aa,bb,hh,t,n,h,countnum=0;
int reverse(int n)
{
    int i=0;
    while(n!=0)
    {
        a[i]=n%10;
        n=n/10;
        i++;
    }
    int k=i;
    for(int j=0; j<i; j++,k--)
        countnum+=a[j]*pow(10,k-1);

    return countnum;
}

int main()
{
    cin>>t;
    for(int i=0; i<t; i++)
    {
        countnum=0;
        cin>>aa>>bb;
        h=reverse(aa);
        hh=reverse(bb);
        cout<<hh<<endl;
    }

    return 0;
}
