// Problem#: 7971
// Submission#: 2040092
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 1000

using namespace std;

struct Node{
    int i, j;
}F[1000000], s;

char G[maxn][maxn];
int W[maxn][maxn], d[maxn][maxn];
int h, w, n;
queue<Node> Q;
const int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

bool isok( int i, int j ) {
    return ( i >= 0 && i < h && j >= 0 && j < w && G[i][j] != '#' );
}

int BFS()
{
    while( !Q.empty() ) Q.pop();
    memset( W,0x7f,sizeof(W) );
    memset( d,0x7f,sizeof(d) );
    for( int i = 0; i < n; i++ ) Q.push( F[i] ), W[ F[i].i ][ F[i].j ] = 0;

    while( !Q.empty() ) {
        Node u = Q.front(); Q.pop();
        for( int i = 0; i < 4; i++ ) {
            int y = u.i+dir[i][0], x = u.j+dir[i][1];
            if( isok( y,x ) && W[y][x] > W[u.i][u.j]+1 ) {
                W[y][x] = W[u.i][u.j]+1;
                Q.push( (Node){y,x} );
            }
        }
    }

    Q.push(s);  d[s.i][s.j] = 0;

    while( !Q.empty() ) {
        Node u = Q.front(); Q.pop();
        for( int i = 0; i < 4; i++ ) {
            int y = u.i+dir[i][0], x = u.j+dir[i][1];
            if( y >= h || y < 0 || x >= w || x < 0 )
                return d[u.i][u.j]+1;
            if( isok(y,x) && d[u.i][u.j]+1 < W[y][x] && d[y][x] > d[u.i][u.j]+1 ) {
                d[y][x] = d[u.i][u.j]+1;
                Q.push( (Node){y,x} );
            }
        }
    }

    return -1;
}

int main()
{
    int Case;   scanf( "%d", &Case );

    while( Case-- ) {
        scanf( "%d%d", &w, &h );    n = 0;

        for( int i = 0; i < h; i++ ) {
            getchar();
            for( int j = 0; j < w; j++ )
            {
                G[i][j] = getchar();
                if( G[i][j] == '*' ) F[n++] = (Node){ i,j };
                else if( G[i][j] == '@' ) s = (Node){ i,j };
            }
        }

        int temp = BFS();
        if( temp == -1 ) puts( "IMPOSSIBLE" );
        else printf( "%d\n", temp );
    }

    return 0;
}
