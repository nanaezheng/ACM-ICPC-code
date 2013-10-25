// Problem#: 4187
// Submission#: 1922921
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[100],t;

int main()
{
    cin>>t;
    while(t--)
    {
        for(int i=0; i<3; i++)
            cin>>a[i];

        sort(a,a+3);
       //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;;
        if(a[0]+a[1]>a[2])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        memset(a,0,sizeof(a));
    }


    return 0;
}
