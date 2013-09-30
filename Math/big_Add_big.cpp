#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define maxn 111

using namespace std;
int n,m,k;
char a[maxn][maxn];
bool flag;

int dfs(int x,int y,int step)
{
    if (flag ) return 0;
    if(step == 0 )
    {
        if (a[x][y] == 'D' && step > 0)
            flag = true;
        return 0;
    }
    if (x + 1 < n && (a[x+1][y] == '.'|| a[x+1][y] == 'D'))
    {
        if (a[x+1][y] == 'D'&& step > 0)
        {
            flag = true;
            return 0;
        }
        a[x+1][y] = '#';
        dfs(x+1,y,step-1);
        a[x+1][y] = '.';
    }
    if (y + 1 < m && a[x][y+1] == '.' || a[x][y+1] == 'D')
    {
        if (a[x][y+1] == 'D'&& step > 0)
        {
            flag = true;
            return 0;
        }
        a[x][y+1] = '#';
        dfs(x,y+1,step-1);
        a[x][y+1] = '.';
    }
    if (x -1 >= 0 && a[x-1][y] == '.' || a[x-1][y] == 'D')
    {
        if (a[x-1][y] == 'D'&& step > 0)
        {
            flag = true;
            return 0;
        }
        a[x-1][y] = '#';
        dfs(x-1,y,step-1 );
        a[x-1][y] = '.';
    }
    if (y -1 >= 0 && a[x][y-1] == '.' || a[x][y-1] == 'D')
    {
        if (a[x][y-1] == 'D'&& step > 0)
        {
            flag = true;
            return 0;
        }
        a[x][y-1] = '#';
        dfs(x,y-1,step -1 );
        a[x][y-1] = '.';
    }
    return 0;
}

int main()
{
    //freopen("E:\\a.in","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if (n == 0 && m == 0 &&  k == 0 ) break;
        memset(a,0,sizeof(a));
        for(int i = 0 ; i< n ; i++ ) scanf("%s",a[i]);
        int x = -1 , y = -1;
        int w = 0 ;
        for(int i = 0 ;i < n ; i++ )
            for(int j = 0 ; j < m ; j++ )
            {
                if (a[i][j] == 'S') x = i , y = j ;
                if (a[i][j] == 'X') w++;
            }
        flag = false;
        dfs(x,y,k);
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
