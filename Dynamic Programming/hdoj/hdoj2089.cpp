#include <iostream>
using namespace std;
bool bingo(int n)
{
    while(n)
    {
        if(n%10==4||n%100==62) return 1;
        n=n/10;
    }
    return 0;
}
int tab[1000010];
int main()
{
    int n,m;
    memset(tab,0,sizeof(tab));
    for(int i=0; i<1000000; i++)
        if(bingo(i)) tab[i]=1;
    while(cin>>n>>m&&(n||m))
    {
        int cont=m-n+1;
        for(int i=n; i<=m; i++)
            if(tab[i]) cont--;
        cout<<cont<<endl;
    }
    return 0;
}
