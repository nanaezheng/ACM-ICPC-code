// Problem#: 8046
// Submission#: 2077728
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
    int num;
    int score;
    bool operator < ( const Node a ) const
    {
        return score < a.score || ( a.score == score && num < a.num );
    }
}node[12];

int n;

int main()
{
    int Case;   scanf( "%d", &Case );
    while( Case-- )
    {
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ )
        {
            scanf( "%d", &node[i].score );
            node[i].num = i+1;
        }
        sort( node, node+n );   int ans = 0, t = -1;
        for( int i = 0; i < n; i++ )
        {
            int temp;   scanf( "%d", &temp );
            node[i].score = max( node[i].score, temp );
            if( ans < node[i].score )
            {
                ans = node[i].score;
                t = node[i].num;
            }
        }

        printf( "%d\n", t );
    }

    return 0;
}
