/*******************************
  Name:
  Copyright:
  Author: Nanae
  Date:
*********************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int f[30001],p[24],v[24],m,N,i,j;
int main()
{
    while(cin>>N>>m)
    {
   memset(f,0,sizeof(f));
   for(i=0;i!=m;i++){
            scanf("%d %d",v+i,p+i);
    p[i]=p[i]*v[i];
   }
        for(j=0;j!=m;j++)
    for(i=N+1;i!=v[j]-1;i--)
      f[i]=max(f[i],f[i-v[j]]+p[j]);
        printf("%d\n",f[N]);
    }
    return 0;
}
