// Problem#: 1147
// Submission#: 1922806
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int count,h,t,i,maxx,avg[1000];
int j=0;
int banji[1000],sum[1000],paper[1000];
char boss[1000],west[1000];
string s[1000];
void init()
{
    count=0;
    maxx=0;
    j=0;
    memset(sum,0,sizeof(sum));
    memset(banji,0,sizeof(banji));
     memset(paper,0,sizeof(paper));
      memset(avg,0,sizeof(avg));
}

int main()
{
    while(cin>>t)
    {
        init();
        for(i=0; i<t; i++)
        {
            cin>>s[i];
            cin>>avg[i]>>banji[i]>>boss[i]>>west[i]>>paper[i];
            if(avg[i]>80&&paper[i]>=1)sum[i]+=8000;
            if(avg[i]>85&&banji[i]>80)sum[i]+=4000;
            if(avg[i]>90)sum[i]+=2000;
            if(avg[i]>85&&west[i]=='Y')sum[i]+=1000;
            if(banji[i]>80&&boss[i]=='Y')sum[i]+=850;
        }
        maxx = sum[0];
        for(i = 0; i <=t; i++)
        {
            if(sum[i] >maxx)
            {
                maxx = sum[i];
                j = i;
            }
        }

        cout<<s[j]<<endl;
        cout<<maxx<<endl;
        for(int i=0; i<t; i++)
            count+=sum[i];

        cout<<count<<endl;
        count=0;
        memset(sum,0,sizeof(sum));
    }

    return 0;
}
