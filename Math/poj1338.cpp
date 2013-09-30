#include<stdio.h>
#include<string.h>
int ugly[1501];
int n,ans;
int min(int a,int b)
{
	return a<b ? a : b;
}
void getugly()
{
	int i;

	int i2_ul=1;
	int i3_ul=1;
	int i5_ul=1;

	ugly[1]=1;

	for(i=2;i<=1500;i++)
	{
		ugly[i]=min(ugly[i2_ul]*2,min(ugly[i3_ul]*3,ugly[i5_ul]*5));

		if(ugly[i] == ugly[i2_ul]*2 )
			i2_ul++;
		if(ugly[i] == ugly[i3_ul]*3 )
			i3_ul++;
		if(ugly[i] == ugly[i5_ul]*5 )
			i5_ul++;
	}

}
int main()
{
	 getugly();
     while(scanf("%d",&n) && n!=0)
	 printf("%d\n",ugly[n]);
	 return 0;
}
