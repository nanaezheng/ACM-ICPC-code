#include<stdio.h>
#include<string.h>
char a[40];
char b[40];
char result[200] ;
char judge[2][11]={"no","good"};
int main()
{
    int n,i,suma,sumb,len;
    while(scanf("%d",&n)&&n!=0)
    {
        getchar();
        suma=sumb=0;              //记录进球数
        if(n%2==1) b[n/2+1]='-';   //如果给的样例是奇数的话 就给b数组附“-”
        for(i=1;i<=n;i++)
        {
            gets(result);
            len=strlen(result);
           if(i%2==1)
                      {
                                  if(len<=6) {suma++;a[i/2+1]='O'; continue;}  //<span style="color:#ff0000;">从后面检查是否存在‘ no’ 切记 n前面的空格</span>

                                  if(result[len-7]!='n'||result[len-6]!='o'||result[len-8]!=' '){suma++;a[i/2+1]='O';continue;}
                                  a[i/2+1]='X';   //没进球 赋值‘X’
                      }
           else    {
                                  if(len<=6) {sumb++;b[i/2]='O'; continue;}
                                  if(result[len-7]!='n'||result[len-6]!='o'||result[len-8]!=' '){sumb++;b[i/2]='O';continue;}
                                  b[i/2]='X';
                     }

        }
        for(i=1;i<=(n+1)/2;i++)
        {
          printf("%d ",i);
        }
        printf("Score\n");
        for(i=1;i<=(n+1)/2;i++)
        {
          printf("%c ",a[i]);
        }
        printf("%d\n",suma);
        for(i=1;i<=(n+1)/2;i++)
        {
          printf("%c ",b[i]);
        }
        printf("%d\n",sumb);

    }
}
