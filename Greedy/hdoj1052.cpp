#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int t[1005],k[1005];

int main()
{
//freopen("acm.txt","r",stdin);
    int i,tmax,kmax,tmin,kmin,n,sum;
    while( scanf("%d",&n)!=EOF )
    {
        if( n==0 )
            break;
        for(i=0; i<n; i++)
            scanf("%d",&t[i]);
        for(i=0; i<n; i++)
            scanf("%d",&k[i]);
        qsort(t,n,sizeof(t[0]),cmp);
        qsort(k,n,sizeof(k[0]),cmp);
        sum=0;
        for(tmin=0,kmin=0,tmax=n-1,kmax=n-1; tmin<=tmax && kmin<=kmax; )
        {
            if( t[tmin]>k[kmin] )
            {
                sum=sum+200;
                tmin++;
                kmin++;
                continue;
            }
            if( t[tmin]<k[kmin] )
            {
                sum=sum-200;
                tmin++;
                kmax--;
                continue;
            }
            if( t[tmin]==k[kmin] )
            {
                if( t[tmax]>k[kmax] )
                {
                    sum=sum+200;
                    tmax--;
                    kmax--;
                    continue;
                }
                if( t[tmax]<k[kmax] )
                {
                    sum=sum-200;
                    tmin++;
                    kmax--;
                    continue;
                }
                if( t[tmax]==k[kmax] )
                {
                    if( t[tmin]<k[kmax] )
                        sum=sum-200;
                    tmin++;
                    kmax--;
                    continue;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
