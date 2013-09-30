// Problem#: 3725
// Submission#: 1922932
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
int a[10000],t,n,countnum=0;

int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);
        cout<<a[n-1]<<endl;
    }

    return 0;
}
