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

const int MAXN = 100010;

char cipher[MAXN];
char plain[MAXN];
char table[50];
char rtable[50];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>table;
        for(int i=0;i<26;++i)
        {
            rtable[table[i] - 'a'] = i + 'a';
        }
        rtable[26] = 0;
        cin>>cipher;
        strcpy(plain, cipher);
        int len = strlen(cipher);
        for(int i=0;i<len;++i)
        {
            cipher[i] = rtable[cipher[i] - 'a'];
        }
        int i;
        for(i=(len+1)/2;i<len;++i)
        {
            int k = i;
            for(int j=0;k<len;++j, ++k)
            {
                if(cipher[j] != plain[k])
                {
                    break;
                }
            }
            if(k == len)
            {
                for(int j=0;j<i;++j)
                {
                    cout<<plain[j];
                }
                for(int j=0;j<i;++j)
                {
                    printf("%c", cipher[j]);
                }
                cout<<endl;
                break;
            }
        }
        if(i == len)
        {
            cout<<plain<<cipher<<endl;
        }
    }
    return 0;
}
