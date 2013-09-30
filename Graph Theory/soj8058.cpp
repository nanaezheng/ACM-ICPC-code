// Problem#: 8058
// Submission#: 2071227
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1002
using namespace std;
int N,M,Q;
int Map[maxn][maxn];
int increase[maxn];

int binary(int a[],int left,int right,int key,int row)
{
    int l,h;
    int m, ans = -1;
    l = left;
    h = right;
    while(l <= h)
    {
        m = (l + h)/2;
        if(a[m]+increase[row] > key)
            h = m - 1;
        else if(a[m]+increase[row] == key)
        {
            ans = m;
            h = m-1;
        }
        else
            l = m + 1;
    }
    return ans;

}


void query(int p,int lx,int rx,int ly ,int ry)
{
    int i,res = -1;
    for(i = lx ; i <= rx ; i++)
    {
        if( Map[i][ry] + increase[i] >= p )
            res = binary(Map[i],ly,ry,p,i);
        if( res != -1 || Map[i][ly] > p ) break;
    }
    if(res != -1) printf("%d %d\n",i,res);
    else printf("-1 -1\n");
}


int main()
{
    int t;
   // freopen("E:\\in.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        memset(increase,0,sizeof(increase));
        scanf("%d %d %d",&M,&N,&Q);
        for(int i = 0 ; i < M ; i ++)
            for(int j = 0 ; j < N ; j ++){
                scanf("%d",&Map[i][j]);}

        while(Q--)
        {
            getchar();
            char od ;
            int lx,rx,ly,ry,x,delta,p;
            scanf("%c",&od);
            if(od=='Q'){
                scanf("%d%d%d%d%d",&p,&lx,&rx,&ly,&ry);
                query(p,lx,rx,ly,ry);
            }
            else{
                scanf("%d%d",&x,&delta);
                increase[x] += delta;
            }
        }
    }
}
