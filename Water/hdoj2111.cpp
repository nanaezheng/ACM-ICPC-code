#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct stuff
{
    int pi;
    int mi;
//double price;
} stuff;
void sort(stuff s[],int len)
{
    int i;
    int j;
    int key1,key2;
    for(i=1; i<len; i++)
    {
        key1=s[i].pi;
        key2=s[i].mi;
        j=i-1;
        while(j>=0&&s[j].pi<key1)
        {
            s[j+1].pi=s[j].pi;
            s[j+1].mi=s[j].mi;
            j--;
        }
        s[j+1].pi=key1;
        s[j+1].mi=key2;
    }
}
int main()
{
    int v,n,i;
    stuff s[101];
    int result;
//freopen("test2.txt","r",stdin);
    while(scanf("%d%d",&v,&n)!=EOF&&v!=0)
    {
        result=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&s[i].pi,&s[i].mi);
        }
        sort(s,n);
        i=0;
        while(i<n&&v>0)
        {
            if(s[i].mi>=v)
            {
                result=result+v*s[i].pi;
                v=0;
            }
            else if(s[i].mi<v)
            {
                result=result+s[i].pi*s[i].mi;
                v=v-s[i].mi;
                i++;
            }
        }
        printf("%d\n",result);
    }
}
