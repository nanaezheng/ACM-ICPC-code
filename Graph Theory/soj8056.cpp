// Problem#: 8056
// Submission#: 2071147
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define maxn 202
#define INF 0x7f7f7f7f

using namespace std;

struct Edge{
    int from, to, cap, flow;
};

vector<int> G[maxn], C[maxn];
vector<Edge> edge;
queue<int> Q;
int n, s, t, m, check[maxn], sum;
bool vis[maxn];
int d[maxn], cur[maxn];

void add_edge( int from, int to, int cap )
{
    edge.push_back( (Edge){ from, to, cap, 0 } );
    edge.push_back( (Edge){ to, from, 0, 0 } );
    int m = edge.size();
    G[from].push_back( m-2 );
    G[to].push_back( m-1 );
}

bool BFS()
{
    memset( vis,0,sizeof(vis) );
    d[s] = 0;   vis[s] = 1;     Q.push(s);

    while( !Q.empty() )
    {
        int u = Q.front();  Q.pop();
        for( int i = 0; i < G[u].size(); i++ )
        {
            Edge &e = edge[ G[u][i] ];
            if( !vis[e.to] && e.cap > e.flow )
            {
                vis[e.to] = 1;
                d[e.to] = d[u]+1;
                Q.push(e.to);
            }
        }
    }

    return vis[t];
}

int DFS( int u, int a )
{
    if( u == t || !a ) return a;
    int flow = 0, f;
    for( int &i = cur[u]; i < G[u].size(); i++ )
    {
        Edge &e = edge[ G[u][i] ];
        if( d[e.to] == d[u]+1 && ( f = DFS( e.to, min( a,e.cap-e.flow ) ) ) > 0 )
        {
            e.flow += f;    edge[ G[u][i]^1 ].flow -= f;
            a -= f;     flow += f;
            if( !a ) break;
        }
    }
    return flow;
}

int Dinic()
{
    int flow = 0;
    while( BFS() )
    {
        memset( cur,0,sizeof(cur) );
        flow += DFS( s,INF );
    }
    return flow;
}

void init()
{
    s = n+m, t = s+1;
    for( int i = 0; i <= t; i++ )
        C[i].clear();
}

void build_network()
{
    sum = 0;
    scanf( "%d%d", &n, &m );    init();
    for( int i = 0; i < n; i++ )
    {
        int num;    scanf( "%d", &num );
        for( int j = 0; j < num; j++ )
        {
            int temp;   scanf( "%d", &temp );
            C[i].push_back( temp );
        }
    }

    for( int i = 0; i < m; i++ )
    {
        int num;    scanf( "%d", &num );
        check[i] = num; sum += num;
    }
}

bool test( int M )
{
    edge.clear();
    for( int i = 0; i <= t; i++ )
        G[i].clear();
    for( int i = 0; i < n; i++ )
        add_edge( s, i, M );
    for( int i = 0; i < m; i++ )
        add_edge( i+n, t, check[i] );
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < C[i].size(); j++ )
        {
            add_edge( i, C[i][j]+n, INF );
        }
    }

    return Dinic() == sum;
}

void solve()
{
    int L = 0, R = sum, M, ans = -1;
    while( L <= R )
    {
        M = (L+R)>>1;
        if( test(M) ) ans = M, R = M-1;
        else L = M+1;
    }
    printf( "%d\n", ans );
}

int main()
{
    int Case;   scanf( "%d", &Case );

    while( Case-- )
    {
        build_network();
        solve();
    }

    return 0;
}
