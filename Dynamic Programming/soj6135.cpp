// Problem#: 6135
// Submission#: 1915168
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include<string>
#include <algorithm>
using namespace std;


int main()
{
    long long  n,m,h,sum=0,a[100000];
    long long s=(-1000000000);
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        cin>>a[i];

    // sort(a+1,a+1,compare);

    for(int h=1; h<=n; h++)
        for(int j=h+1; j<=n; j++)
            for(int i=j+1; i<=n; i++)
            {
                sum=a[h]+a[j]+a[i];
                if(sum<=m)s=max(s,sum);
            }
    cout<<s<<endl;
    return 0;
}
