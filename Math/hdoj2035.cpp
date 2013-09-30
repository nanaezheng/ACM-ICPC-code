#include <iostream>
using namespace std;
int main()
{
    int a,b,ans;
    while(cin>>a>>b)
    {
        if(!a && !b)
            break;
        ans=0;
        a=a%1000;
        int tmp=a;
        while(b-->1)
        {
            a=(a*tmp)%1000;
        }
        cout<<a<<endl;
    }
    return 0;
}
