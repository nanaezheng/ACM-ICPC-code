#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
#define LL long long
int main()
{
    int n, i, t;
	LL x;
	cin>>t;
    for(i = 0; i < t; i ++)
    {
        cin>>n;
        double m = n * log10((double)n);
        double g = m - (LL)m;
        g = pow(10.0, g);
        cout<<(int)g<<endl;
    }
	return 0;
}
