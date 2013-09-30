#include <iostream>

using namespace std ;


int f[500000];
int V, v;
int temp;
//01背包, c表示花费, w表示价值
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
//完全背包,c表示花费, w表示价值
void bagall(int c, int w)
{
	for (v=c; v<=V; v++)
	{
		temp = f[v-c]+w;
		if (temp>f[v])
			f[v] = temp;
	}
}
//多重背包,c表示花费, w表示价值,p表示个数
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
	//当i=N时，可以跳出循环单独计算F[V]
	cout << f[V] << endl;
    //cout << V << endl << v;

    return 0;
}
