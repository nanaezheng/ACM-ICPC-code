// Problem#: 3835
// Submission#: 1922929
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
int a[100],t,n,countnum=0;

double c1,c2,c3,csum,x1,x2,x3,y,y2,y3;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x1>>y>>x2>>y2>>x3>>y3;
        c1=sqrt(((x1-x2)*(x1-x2))+((y-y2)*(y-y2)));
        c2=sqrt(((x1-x3)*(x1-x3))+((y-y3)*(y-y3)));
        c3=sqrt(((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3)));
       // cout<<c1<<c2<<c3;
        csum=c1+c2+c3;
        cout<<setiosflags(ios::fixed);
        cout.precision(5);
        cout<<csum<<endl;
    }
    return 0;
}
