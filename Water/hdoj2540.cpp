#include<iostream>
#include<stdlib.h>
using namespace std;
struct light
{
 int x;
 int h;
};
struct light l[100001];
int cmp(const void *a,const void *b)
{
 return *(int *)a-*(int *)b;
}
int main()
{
 int n,i,t,a,flag;
 double k,max;
 while(cin>>n)
 {
  max=0;
  flag=0;
  if(n==0)
   return 0;
  for(i=0;i<n;i++)
   scanf("%d%d",&l[i].x,&l[i].h);
  qsort(l,n,sizeof(l[0]),cmp);
  scanf("%d/%d",&t,&a);
  for(i=0;i<n;i++)
  {
   k=l[i].x+(l[i].h*1.0/t)*a;      //阴影的长度
   if(k>max)
   {
    max=k;
    flag++;
   }
  }
  cout<<flag<<endl;
 }
 system("pause");
 return 0;

}
