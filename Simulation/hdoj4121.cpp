#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int ff[11][11];
char map[11][11];
bool inside(int x,int y)//判断坐标是否在棋局内
{
    if(x>=1&&x<=10&&y>=1&&y<=9) return true;
    return false;
}
bool solve(int x,int y)//判断点(x,y)是否是危险点,安全点返回  true ,
                      //也就是 将  下一步可以走的点，否则false
{
    bool cmp=true;
    for(int i=x+1;i<=10;i++)
    {
        if(ff[i][y]==1)
        {
            if(map[i][y]=='R'||map[i][y]=='G')
                return false;
            else
                for(int t=i+1;t<=10;t++)
                    if(ff[t][y]==1)
                    {
                        if(map[t][y]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }


    for(int i=x-1;i>=1;i--)
    {
        if(ff[i][y]==1)
        {
            if(map[i][y]=='R'||map[i][y]=='G')
                return false;
            else
                for(int t=i-1;t>=0;t--)
                    if(ff[t][y]==1)
                    {
                        if(map[t][y]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }

    for(int i=y+1;i<=9;i++)
    {
        if(ff[x][i]==1)
        {
            if(map[x][i]=='R'||map[x][i]=='G')
                return false;
            else
                for(int t=i+1;t<=9;t++)
                    if(ff[x][t]==1)
                    {
                        if(map[x][t]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }


    for(int i=y-1;i>=1;i--)
    {
        if(ff[x][i]==1)
        {
            if(map[x][i]=='R'||map[x][i]=='G')
                return false;
            else
                for(int t=i-1;t>=0;t--)
                    if(ff[x][t]==1)
                    {
                        if(map[x][t]=='C')
                            return false;
                        break;
                    }    
            break;
        }
    }
    //下面判断会不会被马吃掉
    if(inside(x-2,y-1))
    {
        if(ff[x-2][y-1])
        {
            if(map[x-2][y-1]=='H'&&ff[x-1][y-1]==0)
                return false;
        }
    }

    if(inside(x+2,y+1))
    {
        if(ff[x+2][y+1])
        {
            if(map[x+2][y+1]=='H'&&ff[x+1][y+1]==0)
                return false;
        }
    }

    if(inside(x-1,y-2))
    {
        if(ff[x-1][y-2])
        {
            if(map[x-1][y-2]=='H'&&ff[x-1][y-1]==0)
                return false;
        }
    }


   if(inside(x+1,y+2))
    {
        if(ff[x+1][y+2])
        {
            if(map[x+1][y+2]=='H'&&ff[x+1][y+1]==0)
                return false;
        }
    }


    if(inside(x+2,y-1))
    {
        if(ff[x+2][y-1])
        {
            if(map[x+2][y-1]=='H'&&ff[x+1][y-1]==0)
                return false;
        }
    }

    if(inside(x+1,y-2))
    {
        if(ff[x+1][y-2])
        {
            if(map[x+1][y-2]=='H'&&ff[x+1][y-1]==0)
                return false;
        }
    }

    if(inside(x-2,y+1))
    {
        if(ff[x-2][y+1])
        {
            if(map[x-2][y+1]=='H'&&ff[x-1][y+1]==0)
                return false;
        }
    }

    if(inside(x-1,y+2))
    {
        if(ff[x-1][y+2])
        {
            if(map[x-1][y+2]=='H'&&ff[x-1][y+1]==0)
                return false;
        }
    }

    return true;
}

int main()
{
    int N,x,y;
    int a,b;
    char ch;
    while(scanf("%d%d%d",&N,&x,&y))
    {
        if(N==0&&x==0&&y==0)break;
        memset(ff,0,sizeof(ff));
        //ch=getchar();
        for(int i=0;i<N;i++)
        {
            cin>>ch>>a>>b;
            map[a][b]=ch;
            ff[a][b]=1;
        }
        bool res=false;
        if(x-1>=1&&x-1<=3)
            if(solve(x-1,y))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        if(x+1>=1&&x+1<=3)
            if(solve(x+1,y))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        if(y-1>=4&&y-1<=6)
            if(solve(x,y-1))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        if(y+1>=4&&y+1<=6)
            if(solve(x,y+1))  res=true;
        if(res)
        {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }
    return 0;
}
