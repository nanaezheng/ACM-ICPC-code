#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m;
int move[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool used[1005][1005];
int flag;
struct State
{
    int x;
    int y;
    int dir;
    int turn;
    int step;
};
State start;
State end;
int map[1005][1005];
bool Judge(State t)
{
    if(t.x==end.x&&t.y==end.y)
        return 1;
    if(t.turn==0)
        return 1;
    if(t.turn==1)
    {
        if(t.x>end.x&&t.dir==1)
            return 0;
        if(t.y>end.y&&t.dir==3)
            return 0;
        if(t.x<end.x&&t.dir==0)
            return 0;
        if(t.y<end.y&&t.dir==2)
            return 0;
        return 1;
    }
    if(t.turn==2)
    {
        if(t.x==end.x)
        {
            if(t.y>end.y&&t.dir==2)
                return 1;
            if(t.y<end.y&&t.dir==3)
                return 1;
        }
        if(t.y==end.y)
        {
            if(t.x>end.x&&t.dir==0)
                return 1;
            if(t.x<end.x&&t.dir==1)
                return 1;
        }
        return 0;
    }
    return 1;
}
void DFS(State t)
{
    if(flag)
        return;
    if(t.turn>2)
        return;
    if(t.x==end.x&&t.y==end.y)
    {
        flag=1;
        return;
    }
    int x,y;
    State temp;
    if(t.step==0)
    {
        for(int i=0;i<4;i++)
        {
            temp.x=t.x+move[i][0];
            temp.y=t.y+move[i][1];
            if(temp.x<=0||temp.y<=0||temp.x>n||temp.y>m||used[temp.x][temp.y]==1)
                continue;

            temp.dir=i;
            temp.turn=0;
            temp.step=t.step+1;

            if(Judge(temp)==0)
                continue;

            used[temp.x][temp.y]=1;
            DFS(temp);
            used[temp.x][temp.y]=0;
        }
        return;
    }
    if(map[t.x][t.y]!=0)
        return;
    for(int i=0;i<4;i++)
    {
        temp.x=t.x+move[i][0];
        temp.y=t.y+move[i][1];
        if(temp.x<=0||temp.y<=0||temp.x>n||temp.y>m||used[temp.x][temp.y]==1)
            continue;
        if(t.dir!=i)
        {
            temp.dir=i;
            temp.turn=t.turn+1;
        }else
        {
            temp.dir=t.dir;
            temp.turn=t.turn;
        }
        temp.step=1;
        if(Judge(temp)==0)
            continue;

        used[temp.x][temp.y]=1;
        DFS(temp);
        used[temp.x][temp.y]=0;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int t;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)
            return 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d %d %d %d",&start.x,&start.y,&end.x,&end.y);
            if(start.x==end.x&&start.y==end.y)
            {
                printf("NO\n");
                continue;
            }
            if(map[start.x][start.y]!=map[end.x][end.y]||map[start.x][start.y]==0||map[end.x][end.y]==0)
            {
                printf("NO\n");
                continue;
            }
            memset(used,0,sizeof(used));
            used[start.x][start.y]=1;
            start.turn=0;
            start.step=0;
            flag=0;
            DFS(start);
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
