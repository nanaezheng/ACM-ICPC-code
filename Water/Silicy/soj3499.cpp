// Problem#: 3499
// Submission#: 1922961
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
int aa,bb,hh,t,n,h;
double avg,sum=0;
double a[10000];

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>t;
        for(int i=0; i<t; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+t);
        avg=(sum-a[0]-a[t-1])/(t-2);
        cout<<setiosflags(ios::fixed);
        cout.precision(2);
        cout<<avg<<endl;
        avg=0;
        sum=0;
        memset(a,0,sizeof(a));

    }

    return 0;
}
