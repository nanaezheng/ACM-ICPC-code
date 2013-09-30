// Problem#: 8047
// Submission#: 2077749
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int dp[1001][1001];
int L[1001], R[1001], Ly[1001], Ry[1001];
int h, X;

int solve()
{
    memset( dp,0x7f,sizeof(dp) );
    dp[0][Ly[0]] = 0;
    for( int i = 1; i <= h; i++ )
    {
        Ly[i] = max( Ly[i-1]-1, L[i] );
        Ry[i] = min( Ry[i-1]+1, R[i] );
        for( int j = Ly[i]; j <= Ry[i]; j++ )
        {
            if( j >= Ly[i-1] && j <= Ry[i-1] )
                dp[i][j] = dp[i-1][j];
            else if( j == Ly[i-1]-1 )
                dp[i][j] = dp[i-1][Ly[i-1]]+1;
            else if( j == Ry[i-1]+1 )
                dp[i][j] = dp[i-1][Ry[i-1]]+1;
        }
    }

    int ans = 0x7f7f7f7f;
    for( int i = L[h]; i <= R[h]; i++ )
        ans = min( dp[h][i], ans );
    return ans;
}

int main()
{
    int Case;   scanf( "%d", &Case );

    while( Case-- )
    {
        scanf( "%d", &h );
        for( int i = 1; i <= h; i++ )
            scanf( "%d", &R[i] );
        for( int i = 1; i <= h; i++ )
            scanf( "%d", &L[i] );

        scanf( "%d", &X );
        Ly[0] = Ry[0] = X;

        int ans = solve();
        if( ans < 0x7f7f7f7f ) printf( "%d\n", ans );
        else puts( "-1" );
    }

    return 0;
}
