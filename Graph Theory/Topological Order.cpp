#include <stdio.h>
int team[505][505];
int degree[505];
int N,M;
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF){
        int i,j;
        for(i=1;i<=N;i++){
            degree[i]=0;
            for(j=1;j<=N;j++)
                team[i][j]=0;
        }
        for(i=1;i<=M;i++){
            int p1,p2;
            scanf("%d%d",&p1,&p2);
            if(!team[p1][p2])
                degree[p2]++;
            team[p1][p2]=1;
        }
        int count;
        for(count=1;count<=N;count++)
        {
            for(i=1;i<=N;i++)
            {
                if(degree[i]==0)
                {
                    degree[i]=-1;
                    for(j=1;j<=N;j++)
                    {
                        if(team[i][j]&&degree[j]>0)
                            degree[j]--;
                    }
                    printf("%d",i);
                    if(count==N)    putchar('\n');
                    else putchar(' ');
                    break;
                }
            }
        }
    }
}


//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//int n,m,i,j,count,p1,p2,team[500][500],degree[500];
//while((cin>>n>>m),n,m)
//{
// for(i=1;i<=n;i++)
// {
// degree[i]=0;
//             for(j=1;j<=n;j++)
//             {
//             team[i][j]=0;
//             }
// }
// for(i=1;i<=m;i++)
// {
// cin>>p1>>p2;
// if(!team[p1][p2])
// degree[p2]++;
// team[p1][p2]=1;
// }
// for(count=1;count<=n;count++)
// {
//  for(i=1;i<=n;i++)
//  {
//   if(degree[i]==0)
//   {
//    degree[i]=-1;
//    for(j=1;j<=n;j++)
//    {
//     if(team[i][j]&&degree[j]>0)degree[j]--;
//    }
//    cout<<i;
//    if(count==n)cout<<endl;else cout<<" ";
//    break;
//   }
//  }
// }
//}
//}

