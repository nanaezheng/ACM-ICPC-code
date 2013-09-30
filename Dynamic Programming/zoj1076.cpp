//LISµÄ±äÐÎ

#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
struct NODE
{
    int x, y, id;
    bool operator<(const NODE& a) const
    {
        if( a.x == x )
            return y < a.y;
        return x < a.x;
    }
};
NODE a[MAXN];
int m[MAXN];
int pre[MAXN];
int n;
void solve(int n)
{

    sort(a, a+n);

    m[0] = 1;
    pre[0] = -1;
    for(int i=1; i<n; i++)
    {
        int mm = 0;
        int t = -1;
        for(int k=0; k<i; k++)
        {
            if( a[i].x > a[k].y )
            {
                mm = m[k];
                t = k;
            }
        }
        m[i] = mm + 1;
        pre[i] = t;
    }

    int out[MAXN], cnt = 0;
    int maxl = *max_element(m, m+n);
    for(int i=n-1; i>=0; i--)
        if( m[i] == maxl )
        {
            while( i != -1 )
            {
                out[cnt++] = a[i].id;
                i = pre[i];
            }
            break;
        }
    for(int i=cnt-1; i>0; i--)
        cout << out[i] << ' ';
    cout << out[0] << endl;
}
void input()
{
    for(int i=0; i<n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
    }
}
int main()
{
    while( cin >> n)
    {
        if(n==0)break;
        input();
        solve( n );
    }
    return 0;
}
