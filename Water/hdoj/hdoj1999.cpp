#include<iostream>
using namespace std;
int main()
{
    int n,t,i,j,q;
    int a[1001]={0};
    a[0]=1;a[1]=1;

    for(i=2;i<=1000;i++)
    {
        if(a[i]==0)
        {
            for(j=i+i;j<=1000;j=j+i)
            {
                a[j]=1;
            }
        }
    }

    cin>>t;
    while(t--)
    {
        cin>>n;
        n=n-1;
        q=0;
        if(a[n]==0)
            q=1;
        else
        {
            for(i=2;i<=n/2;i++)
            {
                if(a[i]==0&&a[n-i]==0&&i!=n-i)
                {
                    q=1;break;
                }
            }
        }

            if(q==0)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
    }
    return 0;
}
