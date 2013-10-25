#include <cstdio>
#include <cstring>
#define max(a, b) (a)>(b)? (a):(b)
using namespace std;
struct node
{
    int v, next;
}edge[202];
int cnt = 0, n = 0, m = 0, value[202], head[202], uead[202], dp[202][202];

void addedge(int u, int v)
{
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int cur)
{
    int i = 0, j = 0, t = 0, p = 0, v = 0, max = 0;
    dp[cur][0] = 0;
    for(p = head[cur]; p != -1; p = edge[p].next)
    {
        v = edge[p].v;
        dfs(v);
        for(i = m; i>0; i--)
        {
            max = dp[cur][i];
            if(cur == 0) t = i;//由于点0不用攻克， 所以当节点为0时只选它的子树
            else t = i-1;//不是根节点， 要攻克它自身
            for(j = 0; j<=t; j++)
                max = max(max, dp[v][j]+dp[cur][i-j]);
//            if(cur == 0) j = 0;  //与上面转移方程一样
//            else j = 1;
//            for(; j<=i; j++)
//                max = max(max, dp[v][i-j]+dp[cur][j]);
            dp[cur][i] = max;
        }
    }
    for(i = 1; i<=m; i++)//加上自己本身
        dp[cur][i] += value[cur];
}

int main()
{
    int i = 0, u = 0, ans = 0, cost = 0, n = 0, cnt2 = 0, num[202];
    while(scanf("%d %d", &n, &m), n+m)
    {
        value[0] = 0;
        memset(head, -1, sizeof(head));
        memset(edge, 0, sizeof(edge));
        memset(dp, 0, sizeof(dp));
        cnt = cnt2 = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%d %d", &u, &cost);
            value[i+1] = cost;
            addedge(u, i+1);
        }
        dfs(0);
        printf("%d\n", dp[0][m]);
    }
    return 0;
}
