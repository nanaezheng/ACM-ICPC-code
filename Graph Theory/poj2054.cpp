#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
class T{
public:
    long long c,t,cost;
    int p,v;
    bool use;
};
const int N = 1010;
T tr[N*2];
int to[N*N],nxt[N*N];
int ep,tp,time;
inline void add(int i,int kid)
{
    ep++;
    to[ep]=kid;
    nxt[ep]=tr[i].v;
    tr[i].v=ep;
    tr[kid].p=i;
}
void init(int n,int rt)
{
    int i,j,k,a,b;
    long long c;

    ep=0,tp=n,time=0;
    for(i=1;i<=n;i++){
        tr[i].t=1;
        tr[i].v=-1;
        tr[i].use=1;
    }
    for(i=1;i<=n;i++){
        cin>>c;
        tr[i].c=tr[i].cost=c;
    }
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    tr[rt].p=-1;
}
void uni(int par,int kid)
{
    int i,j,a,b;

    tp++;
    tr[tp].c=tr[par].c+tr[kid].c;
    tr[tp].cost=tr[par].cost+tr[kid].cost+tr[kid].c*tr[par].t;
    tr[tp].p=tr[par].p;
    tr[tp].t=tr[par].t+tr[kid].t;
    tr[par].use=tr[kid].use=0;
    tr[tp].use=1;
    tr[tp].v=-1;
    for(i=tr[par].v;i!=-1;i=nxt[i]){
        if(to[i]!=kid)
            add(tp,to[i]);
    }
    for(i=tr[kid].v;i!=-1;i=nxt[i]){
        add(tp,to[i]);
    }
    if(tr[tp].p!=-1){
        for(i=tr[tr[tp].p].v;i!=-1;i=nxt[i]){
            if(to[i]==par){
                to[i]=tp;
                break;
            }
        }
    }
}
inline bool first(int a,int b)//a 放在 b之前?
{
    return tr[a].c*tr[b].t>tr[b].c*tr[a].t;
}
long long greedy(int n)
{
    long long ans=0;
    int i,j,k,mm;

    for(k=1;k<=n;k++){
        for(mm=-1,i=1;i<=tp;i++){
            if(tr[i].use==1&&(mm==-1||first(i,mm)))
                mm=i;
        }
        if(tr[mm].p==-1){
            ans+=time*tr[mm].c+tr[mm].cost;
            time+=tr[mm].t;
            for(i=tr[mm].v;i!=-1;i=nxt[i])
                tr[to[i]].p=-1;
            tr[mm].use=0;
        }
        else
            uni(tr[mm].p,mm);
    }
    return ans;
}
int main()
{
    int rt,n;

    while(scanf("%d %d",&n,&rt)==2&&(rt||n)){
        init(n,rt);
        cout<<greedy(n)<<endl;
    }
    return 0;
}
