// Problem#: 8055
// Submission#: 2071010
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long n, m, k;

int main()
{
    int Case;   scanf( "%d", &Case );

    while( Case-- )
    {
        scanf( "%lld%lld%lld", &n, &m, &k );
        if( k <= n ) { printf( "%lld\n", k ); continue; }
        if( k > n*(n/m+1) - n/m*(n/m+1)/2*m ) { printf( "0\n" ); continue; }
        long long L = 0, R = n/m-1, M, ans = -1;
        while( L <= R )
        {
            M = (L+R)>>1;
            if( n*(M+1) - M*(M+1)/2*m <= k-1 ) ans = M, L = M+1;
            else R = M-1;
        }

        printf( "%lld\n", k-n*(ans+1)+ans*(ans+1)/2*m+m*(ans+1) );
    }

    return 0;
}
