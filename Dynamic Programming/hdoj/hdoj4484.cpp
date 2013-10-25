#include <iostream>
#include <cstdio>

using namespace std;

int n, Max, m;
long long ans[100001];

long long get( long long n )
{
    long long Max = n;
    while( n != 1 )
    {
        if( n%2 ) n = n*3+1;
        else n /= 2;
        if( n > Max ) Max = n;
    }
    return Max;
}

int main()
{
    int Case;    scanf( "%d", &Case );

    for( long long i = 1; i <= 100000; i++ )
        ans[i] = get(i);

    while( Case-- )
    {
        scanf( "%d%d", &m, &n );
        printf( "%d %lld\n", m, ans[n] );
    }

    return 0;
}
