// Problem#: 3980
// Submission#: 2041050
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include <string>
#include <cstdio>
using namespace std;

long long bin( string str )
{
    long long sum = 0, len = str.length();
    for( int i = 0; i < len; i++ ) {
        sum<<=1;    sum += str[i]-'0';
    }
    return sum;
}

string ten( long long num )
{
    string str;
    if(!num) str = "0";
    while( num ) {
        int n = num&1;
        num>>=1;
        if( n ) str = "1"+str;
        else str = "0"+str;
    }
    return str;
}

int main()
{
    int  t;
    string str;
    cin>>t;
    while( t-- ) {
        cin>>str;
         cout<<bin(str)<<endl;
    }
    return 0;
}
