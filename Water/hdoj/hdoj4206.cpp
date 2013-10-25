#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double m,f,a,n,h,b;
    int  t,x;
    cin>>t;
    while(t--)
    {
        cin>>m;
        while (h!=m)
        {
            f=sqrt(m);
            n=f+1;
            //a=n*n;
            //b=a-m;

            h=sqrt(n*n-m);

            if(fabs(h-(int(h)) < 1e-8))
            {
                cout<<h<<" "<<n<<endl;
            }
            else
            {
                //cout<<"improssible"<<endl;
                h=h+1;
                n=n+1;
                n=(int)n;

            }
        }
        //cout<<"impossible"<<endl;
    }

}
