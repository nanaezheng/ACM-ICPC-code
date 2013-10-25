#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct a
{
    char name[1000];
    int m,s;
    int tim;
    int num;
} d[110];
int cmp(a x,a y)
{
    return (x.tim==y.tim? strcmp(x.name,y.name)>1:x.tim<y.tim);
}
int main()
{
    int n,i,k=1;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0; i<n; i++)
        {
            scanf("%s %d:%d",d[i].name,&d[i].m,&d[i].s);
            d[i].tim=d[i].m*60+d[i].s;
        }
        sort(d,d+n,cmp);
        if(k!=1) cout<<endl;
        cout<<"Case #"<<k++<<endl;
        for(i=0; i<n; i++)
        {
            if(i>=1&&d[i].tim==d[i-1].tim)
                d[i].num=d[i-1].num;
            else
                d[i].num=i+1;
            cout<<d[i].name<<" "<<d[i].num<<endl;
        }
    }
    return 0;
}
