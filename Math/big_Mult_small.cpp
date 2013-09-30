// 大数乘小数
// 大数a乘以小数b，结果返回给s
#include<iostream>
#include<stdio.h> 
#include <string>
#include <math.h>
using namespace std;
char a[100],s[100];
int  b;
void big_Mult_small(char a[], int b, char s[])
{
	int m[1000], p[1000];
	// 初始化
	memset(m, 0, sizeof(m));
	memset(p, 0, sizeof(p));
	int len = strlen(a);
	// 把a逆序赋给m整形数组
	for(int i=0; i<len; ++i)
		m[i] = a[len-i-1]-'0';
	// 相乘
	for(int i=0; i<len; ++i)
		p[i] = m[i]*b;
	// 处理
	for(int i=0; i<len; ++i)
		if(p[i]>=10)
		{
			p[i+1] += p[i]/10;
			p[i] = p[i]%10;
		}
	while(p[len])
	{
		if(p[len]>=10)
		{
			p[len+1] += p[len]/10;
			p[len] = p[len]%10;
		}
		len++;
	}
	for(int i=0; i<len; ++i)
		s[i] = p[len-i-1]+'0';
	s[len] = 0;
	cout<<s;
}


int main()
{
cin>>a>>b;    
big_Mult_small(a,b,s);
system("Pause"); 
}
