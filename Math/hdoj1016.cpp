#include <iostream>
#include <cstring>
using namespace std;

int p[105],f[21],a[21];//p[]��������f[i]�Ǳ�־Ԫ��i���Ѿ���ʹ�ù���a[i]��¼���

void prim()
{
    //��ɸѡ����һ������������Ŀ��֪��n ��󲻳���20������ÿ������Ԫ��֮��һ�����ᳬ��40
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
    // kΪ��һ��Ԫ�ص�ֵ��mΪ��������m��Ԫ�أ�nΪ��Χ
    int i,flag;
    if( m==n+1 )
    {
        //��������һ��Ԫ��
        if( p[1+k]==1 )
        {
            //�ж����һ��Ԫ�����һ��Ԫ��1�ĺ��Ƿ�Ϊ���������Ϊ����������������Ϊ���������
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
            if( f[i]==0 && p[i+k]==1 )//���Ԫ��δ�����ʹ���������ǰһ��Ԫ��֮��Ϊ���������������
            {
                a[m]=i;
                f[i]=1;// i�ı�־f[i]��1��ʾ�����ʹ�
                dfs(i,m+1,n);//��������
                f[i]=0;// i�ı�־��0
            }
        }
    }
}

int main()
{
// freopen("acm.txt","r",stdin);
    int n,i,j,t=1;
    prim();//��������
    while( cin>>n )
    {
        memset(f,0,sizeof(f));//���з����³�ʼ״̬0
        f[1]=1;
        a[1]=1;//��һ��Ԫ�رض�Ϊ1
        cout<<"Case "<<t<<':'<<endl;
        dfs(1,2,n);//����
        cout<<endl;//û������Ŀ��û����س����з�����ʱ������
        t++;
    }
    return 0;
}
