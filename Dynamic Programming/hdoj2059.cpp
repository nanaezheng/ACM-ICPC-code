#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;
int d[110];
double dp[110];
int main()
{
    int n, c, t, l;
    int vr, v1, v2;
    while(cin>>l)
    {
        cin>>n>>c>>t;
        cin>>vr>>v1>>v2;

        for(int i = 1; i <= n; i++)
            cin>>d[i];
        d[n+1] = l;
        d[0] = 0;
        dp[0] = 0;
        for(int i = 1; i <= n + 1; i++)
        {
            double min=1.0*l/v2;
            for(int j = 0; j < i; j++)
            {
                int len = d[i] - d[j];
                double ti=j? t:0;
                ti += len > c ? 1.0 * c / v1 + 1.0 * (len - c) / v2 : 1.0 * len / v1;
                ti += dp[j];
                if(min>ti) min=ti;

                ti = 1.0 * len / v2;
                ti += dp[j];
                if(min > ti)  min = ti;
            }
            dp[i] = min;
        }
        printf(1.0*l/vr>dp[n+1] ? "What a pity rabbit!\n" : "Good job,rabbit!\n");
    }
    return 0;
}
