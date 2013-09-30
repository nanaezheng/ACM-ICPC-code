// Problem#: 1687
// Submission#: 1920584
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int f[101][101];

int main()
{
    int n,k;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(n=1;n<=100;n++)
        for(k=0;k<n;k++)
            f[n][k]=(f[n-1][k]*(k+1)+f[n-1][k-1]*(n-k))%2007;

    while(cin>>n>>k)
     cout<<f[n][k]<<endl;
    return 0;
}
