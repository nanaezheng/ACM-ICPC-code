#include <iostream>
#include <cstring>
using namespace std;

int p[105],f[21],a[21];//p[]是素数表，f[i]是标志元素i是已经否被使用过，a[i]记录结果

void prim()
{
    //用筛选法打一个素数表，有题目可知，n 最大不超过20，所以每两个个元素之和一定不会超过40
    int i,r,t,s;
    for(i=0; i<=100; i++)
        p[i]=1;
    p[0]=0;
    p[1]=0;
    for(i=4; i<=100; i=i+2)
        p[i]=0;
    r=2;
    while( r*r<=100 )
    {
        r++;
        while( p[r]==0 )
            r++;
        t=r*r;
        s=2*r;
        while( t<=100 )
        {
            p[t]=0;
            t=t+s;
        }
    }
}

void dfs(int k,int m,int n)
{
    // k为上一个元素的值，m为搜索到第m个元素，n为范围
    int i,flag;
    if( m==n+1 )
    {
        //如果是最后一个元素
        if( p[1+k]==1 )
        {
            //判断最后一个元素与第一个元素1的和是否为素数，如果为素数则输出结果，不为素数则不输出
            for(i=1; i<=n; i++)
            {
                if( i==n )
                    cout<<a[i]<<endl;
                else
                    cout<<a[i]<<' ';
            }
        }
    }
    else
    {
        for(i=2; i<=n; i++)
        {
            if( f[i]==0 && p[i+k]==1 )//如果元素未被访问过，并且与前一个元素之和为素数，则继续搜索
            {
                a[m]=i;
                f[i]=1;// i的标志f[i]致1表示被访问过
                dfs(i,m+1,n);//继续搜索
                f[i]=0;// i的标志致0
            }
        }
    }
}

int main()
{
// freopen("acm.txt","r",stdin);
    int n,i,j,t=1;
    prim();//打素数表
    while( cin>>n )
    {
        memset(f,0,sizeof(f));//搜有符号致初始状态0
        f[1]=1;
        a[1]=1;//第一个元素必定为1
        cout<<"Case "<<t<<':'<<endl;
        dfs(1,2,n);//搜索
        cout<<endl;//没看清题目，没输出回车换行符被罚时了两次
        t++;
    }
    return 0;
}
