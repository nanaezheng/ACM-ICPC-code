// Problem#: 1001
// Submission#: 1922747
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>
#include <stack>
#define LL long long
using namespace std;
LL dp[1000000];
int main()
{

    string s;
    dp[0] = 1;
    dp[1] = 1;dp[2] = 2;
    LL i;
    for(i = 3;i < 1000000;i ++)
        dp[i] = dp[i-1] + dp[i-2];
    LL ans,j;
    while(cin>>s)
    {
        if(s == "0") break;
        ans = 1;
        LL len = s.size();
        LL k;
        k = 0;
        s += '7';
        for(i = 0;i <= len;i ++)
        {
            if(s[i] == '0') {ans *= dp[k-1];k = 0;}
            else if(s[i] <= '2') k ++;
            else
            {
                //cout<<k+1<<endl;
                if(i == len) ans *= dp[k];
                else ans *= dp[k+1];
                k = 0;
            }
        }
        cout<<ans<<endl;
    }

}
