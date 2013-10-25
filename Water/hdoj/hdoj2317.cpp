#include<iostream>
using namespace std;
int main()
{
    int n;
    int r,e,c;
    cin>>n;
    while(n--)
    {
        cin>>r>>e>>c;
        if(r==e-c)
            cout<<"does not matter"<<endl;
        else if(r<e-c)
            cout<<"advertise"<<endl;
        else
            cout<<"do not advertise"<<endl;
    }
    return 0;
}
