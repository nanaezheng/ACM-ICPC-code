#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[100010], b[100010];

void deal(int N ,int S,int W)
{
    int g = S;
    for (int i=0; i<N; i++) {
        a[i] = g;
        if( a[i] == 0 ) { a[i] = g = W; }
        if( g%2 == 0 ) { g = (g>>1); }
        else           { g = (g>>1) ^ W; }

        if(i != 0) a[i] = a[i]^a[i-1];
    }
}

int main()
{
    int t;
    cin >> t;
    int n,s,w;
    while(t--)
    {
        cin >> n >> s >> w;
        deal(n,s,w);

        memset(b,0,sizeof(0));
        sort(a,a+n);
        int kk = 1;
        b[0] = 1;
        for(int i = 1;i < n;i++)
        {
            if(a[i] != a[i-1])
            {
                b[kk] = 1;a[kk++] = a[i];
            }
            else b[kk-1]++;
        }
        long long re = 0;
        //for(int i = 0;i < kk;i++) cout << a[i] << " " << b[i] << "\n";
        for(int i = 0;i < kk;i++)
            re += (long long)(n - b[i]) * b[i];

        re = re/2;
        re += n;
        if(a[0] == 0) re -= b[0];

        cout << re << "\n";
    }
    return 0;
}
