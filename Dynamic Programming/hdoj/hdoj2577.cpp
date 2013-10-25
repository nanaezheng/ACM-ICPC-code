#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int on[110],off[110];
    int t;
    char str[110];
    cin>>t;
    while(t--)
    {
        int i;
        cin>>str;
        on[0]=1;
        off[0]=0;
        for(i=1; i<=strlen(str); i++)
        {
            if(str[i-1]<='Z')
            {
                on[i]=min(on[i-1]+1,off[i-1]+2);
                off[i]=min(on[i-1]+2,off[i-1]+2);
            }
            else
            {
                on[i]=min(on[i-1]+2,off[i-1]+2);
                off[i]=min(on[i-1]+2,off[i-1]+1);
            }
        }
        cout<<off[i-1]<<endl;
    }
    return 0;
}
