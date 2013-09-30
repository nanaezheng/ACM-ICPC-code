#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#define maxn 120
using namespace std;
int map[maxn][maxn];
int vis[2010];
struct edge
{
    int to;
    int next;
}e[20010];
int box[2010],cnt;
void init()
{
    cnt=0;
    memset(box,-1,sizeof(box));
}
void add(int from,int to)
{
   e[cnt].to=to;
   e[cnt].next=box[from];
   box[from]=cnt++;
}
int dfs(int now)
{
    vis[now]=1;
    int num=1;
    for(int t=box[now];t+1;t=e[t].next)
    {
        int v=e[t].to;
        if(!vis[v])
        num+=dfs(v);
    }
    return num;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&(m+n))
    {
        int i,x,y;
        init();
        memset(map,0,sizeof(map));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=map[x+1][y]=i;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            if(map[x][y])
            {
                add(map[x][y],i+n);
                add(i+n,map[x][y]);
            }
            if(map[x][y+1])
            {
                add(map[x][y+1],i+n);
                add(i+n,map[x][y+1]);
            }
        }
        int ans=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n+m;i++)
        {
            if(!vis[i])
            {
                int tmp=dfs(i);
                ans+=(tmp+1)/2;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
