// ����������
// ����a��ȥ����b��ֵ����s
#include<iostream>
#include<stdio.h> 
#include <string>
#include <math.h>
using namespace std;

char a[1000],b[1000],s[1000];

void big_Minus_big(char a[], char b[], char s[])
{
	int m[1000], n[1000], p[1000];
	// ��ʼ��
	memset(m, 0, sizeof(m));
	memset(n, 0, sizeof(n));
	memset(p, 0, sizeof(p));
	int len_a = strlen(a);
	int len_b = strlen(b);
	// ���a<b�����a,b�����������
	if(len_a<len_b || strcmp(a, b) < 0)
	{
		char tmp[1000];
		strcpy(tmp, a);
		strcpy(a, b);
		strcpy(b, tmp);
		s[0]='-';
	}
	// ��a���򸳸�m��������
	for(int i=0; i<len_a; ++i)
		m[i] = a[len_a-i-1]-'0';
	// ��b���򸳸�n��������
	for(int i=0; i<len_b; ++i)
		n[i] = b[len_b-i-1]-'0';
	int len = len_a;
	// �������
	for(int i=0; i<len; ++i)
		p[i] = m[i]-n[i];
	// ����
	for(int i=0; i<len; ++i)
		if(p[i] < 0)
		{
			p[i+1] -= 1;
			p[i] += 10;;
		}
	// �������λ
	while(p[len]>0)
		len--;
	// ����char������s��ע�⸺��'-'
	if(s[0] == '-')
	{
		for(int i=1; i<=len; ++i)
			s[i] = p[len-i]+'0';
			s[len+1] = 0;
	}
	else
	{
		for(int i=0; i<len; ++i)
			s[i] = p[len-i-1]+'0';
			s[len] = 0;
	}
	cout<<s;
}

int main()
{
cin>>a>>b;    
big_Minus_big(a,b,s);
system("Pause"); 
}
