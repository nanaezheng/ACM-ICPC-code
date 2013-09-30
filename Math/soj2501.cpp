// Problem#: 2501
// Submission#: 1923887
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University

//费马小定理

#include<iostream>
using namespace std;

int  pow(int A, int  B)
{
    int  R = 1, D = A;
    while (B )
    {
        if (B&1) R = (R * D)%9901 ;
        D = (D * D) %9901 ;
        B >>=1;
    }
    return R;
}

int f(int n,int k)
{
//    cout << n << "   " << k << endl;

    if(k == 1) return n %9901;
    if(k & 1) return (pow(n,k) + f(n,k - 1)) % 9901;
    else return f(n,k / 2) * (1 + pow(n,k / 2))% 9901;
}


int main()
{
    int n,k,i,j;
    cin>>n>>k;
    if(!k)
    {
        cout << 0 << endl;
        return 0;
    }
    i=f(n,k)%9901;
    cout<<i<<endl;



    return 0;
}
