// Problem#: 7144
// Submission#: 1922925
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100],t,n,countnum=0;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                    if(a[i]+a[j]>a[k])countnum++;

        cout<<countnum<<endl;
        countnum=0;

    }


    return 0;
}
