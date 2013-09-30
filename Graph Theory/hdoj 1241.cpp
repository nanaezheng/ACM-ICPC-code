#include <iostream>
#include <queue>
using namespace std;
char map[101][101];
int visited[101][101],n,m;
int dis[8][2]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
struct node
{
    int x;
    int y;
};
void Init()
{
    int i,j;
    for(i=0; i<n; i++)
    {
        scanf("%s",map[i]);
        for(j=0; j<m; j++)
            visited[i][j]=0;
    }
}
void Bfs(int x,int y)
{
    int i;
    queue <node> q;
    node p1,p2;
    p1.x=x;
    p1.y=y;
    visited[x][y]=1;
    q.push(p1);
    while(!q.empty())
    {
        p1=q.front();
        q.pop();
        for(i=0; i<8; i++)
        {
            p2.x=p1.x+dis[i][0];
            p2.y=p1.y+dis[i][1];
            if(p2.x<0||p2.x>=n||p2.y<0||p2.y>=m||visited[p2.x][p2.y]==1||map[p2.x][p2.y]=='*')
                continue;
            visited[p2.x][p2.y]=1;
            q.push(p2);
        }
    }
}
void Solve()
{
    int i,j,k=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            if(map[i][j]!='*'&&visited[i][j]==0)
            {
                k++;
                Bfs(i,j);
            }
    printf("%d\n",k);
}
int main()
{
    // freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            break;
        Init();
        Solve();
    }
    return 0;
}


