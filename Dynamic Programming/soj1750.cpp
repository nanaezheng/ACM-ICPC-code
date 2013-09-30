// Problem#: 1750
// Submission#: 1971329
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
//典型的分组背包
#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

struct  Match
{
    int d;
    int e;
    int m;
    Match (int dd,int ee,int mm)
    {
        d=dd;
        e=ee;
        m=mm;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,n,now,last,sum=0;
        cin>>p>>n;
        vector<Match> mat[n+1];
        int D,E,M;
        if(n==1)
        {
            sum=1;
            cin>>D>>E>>M;
            mat[1].push_back(Match(D,E,M));
        }
        else
        {
            cin>>D>>E>>M;
            mat[1].push_back(Match(D,E,M));
            sum=1;
            last=D;
            for(int i=1; i<n; i++)
            {
                cin>>D>>E>>M;
                now=D;
                if(now==last)
                {
                    mat[sum].push_back(Match(D,E,M));
                }
                else
                {
                    sum++;
                    mat[sum].push_back(Match(D,E,M));
                }
                last=D;
            }
            sum++;
        }

        int f[sum+1][p+1];
        memset(f,0,sizeof(f));

        for(int i=1; i<=sum; i++)
            for(int v=p; v>=0; v--)
            {
                f[i][v]=f[i-1][v];
                for(int kk=0; kk<mat[i].size(); kk++)
                {
                    if(v-mat[i][kk].e>=0)
                        f[i][v]=max(f[i][v],f[i-1][v-mat[i][kk].e]+mat[i][kk].m);
                }
            }
        cout<<f[sum][p]<<endl;
    }
}
