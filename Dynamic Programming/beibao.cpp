#include <iostream>

using namespace std ;


int f[500000];
int V, v;
int temp;
//01����, c��ʾ����, w��ʾ��ֵ
void bag01(int c, int w)
{
	for (v=V; v>=c; v--)
	{
		temp = f[v-c]+w;
		if (temp>f[v])
			f[v] = temp;
	}
//cout << f[v] << '\n';
}
//��ȫ����,c��ʾ����, w��ʾ��ֵ
void bagall(int c, int w)
{
	for (v=c; v<=V; v++)
	{
		temp = f[v-c]+w;
		if (temp>f[v])
			f[v] = temp;
	}
}
//���ر���,c��ʾ����, w��ʾ��ֵ,p��ʾ����
void bagmuti(int c, int w, int p)
{
	int k = 1;
	if (c*p>=V)
		bagall(c, w);
	else
	{
		while (k<p)
		{
			bag01(c*k, w*k);
			p-=k, k+=k;
		}
		bag01(c*p,w*p);

	}
}

int c[1001], w[1001];

int main()
{
    int N,T;


	cin >> N >> V;
	int i = 1;
    memset(f,0,sizeof(f));
    for (; i <= N; ++i)
	{
		cin >> c[i];
	}
	for(i=1;i<=N;++i)
	{
        cin >> w[i];
    }
	for (i = 1; i <= N; ++i)
	{
		bagall(c[i],w[i]);
	}
	//��i=Nʱ����������ѭ����������F[V]
	cout << f[V] << endl;
    //cout << V << endl << v;

    return 0;
}
