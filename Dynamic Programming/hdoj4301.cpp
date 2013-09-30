#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
template<class T>inline T iabs(const T& v) {return v<0 ? -v : v;}
template<class T>inline T strTo(string s){istringstream is(s);T v;is>>v;return v;}
template<class T>inline string toStr(const T& v){ostringstream os;os<<v;return os.str();}
template<class T>inline int cMin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T>inline int cMax(T& a, const T& b){return a<b?a=b,1:0;}
template<class T>inline int cBit(T n){return n?cBit(n&(n-1))+1:0;}
#define ep 1E-10
#define CLR(arr,v)   memset(arr, v, sizeof(arr))
#define SQ(a)  ((a)*(a))
#define DEBUG(a)     printf("%s = %s\n", #a, toStr(a).c_str())
#define FOR(i,s,e) for( u64  (i)=(s); (i) < (e) ; i++)
//Const u64 inf3 = 0x15fffffffffffffffll;
int inf4 = 0x7fffffffl;
typedef long long u64;

#define M 100000007
using namespace std;
typedef long long LL;
LL f[1005][2][2010];

int main()
{
    int i,j,n,m,t;
    f[1][0][1] = f[1][1][2] = 1;
    for(i=1; i<=1000; i++)
       for(j=1; j<=2*i; j++){
         f[i+1][0][j]=(f[i+1][0][j]+f[i][0][j]+f[i][1][j]*2)%M;
         f[i+1][0][j+1]=(f[i+1][0][j+1]+f[i][0][j]+f[i][1][j])%M;
         f[i+1][1][j]=(f[i+1][1][j]+f[i][1][j])%M;
         f[i+1][1][j+1]=(f[i+1][1][j+1]+f[i][0][j]*2+f[i][1][j]*2)%M;
         f[i+1][1][j+2]=(f[i+1][1][j+2]+f[i][0][j]+f[i][1][j])%M;
       }
    cin>>t;
    while(t--)
    {
       cin>>n>>m;
        cout<<(f[n][0][m]+f[n][1][m])%M<<endl;
    }
    return 0;
}
