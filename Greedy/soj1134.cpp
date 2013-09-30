#include<iostream>
#include<algorithm>
using namespace std;
struct child
{
    int a;
    int b;
};

bool cmp(child cc1, child cc2)
{
    if(cc2.b > cc1.b)
        return true;
    else if(cc1.b == cc2.b && cc2.a < cc1.a)
        return true;
    else return false;
}

int main()
{
    int n,s;
    while(cin>>n && n!=0)
    {
        cin>>s;
        child c[n];
        int a,b;
        for(int i=0; i<n; i++)
        {
            cin>>a>>b;
            c[i].a = a;
            c[i].b = b;
        }
        sort(c,c+n,cmp);
        int j;
        for( j=0; j<n; j++)
        {
            if(c[j].b <= s)
                s += c[j].a;
            else
                break;
        }
        if(j == n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
