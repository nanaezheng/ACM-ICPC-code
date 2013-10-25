// Problem#: 1197
// Submission#: 1921895
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
char s[1000];
bool m[100][100];
char w[1000];
void init()
{
    for(int i=0; i<strlen(w); i++)
        for(int j=0; j<strlen(s); j++)
            m[i][j]=false;
    m[0][0]=true;
}
bool match(char *w,char *s)
{
    init();
    for(int i=1; i<=strlen(w); i++)
        for(int j=0; j<=strlen(s); j++)
            if(w[i-1]=='*')
                m[i][j]=(!j)?(m[i-1][j]):(m[i][j-1]|m[i-1][j]);
            else if(w[i-1]=='?')
                m[i][j]=m[i-1][j-1];
            else
                m[i][j]=m[i-1][j-1]&(w[i-1]==s[j-1]);
    return m[strlen(w)][strlen(s)];
}
void solve()
{
    int i,n,count=0;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>s;
        if(match(w,s))count++;
    }
    cout<<count<<endl;
}
int main()
{
    while(cin>>w)
        solve();
    return 0;

}
