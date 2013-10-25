#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <stack>
#include <cstring>
#include <math.h>
#include <string.h>
#include <string>
#include<sstream>
using namespace std;

string dtos(double n)
{
    char c[32];
    gcvt(n,32,c);
    string str(c);
    str.erase(str.length()-1);
    return str;
}

double stod(string str)
{
    double n=atof(str.c_str());
    return n;
}

int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            bool flag=true;
            int step=0;
            int num;
            cin>>num;
            while(num!=1)
            {
                if(num%2==1)
                {
                    flag=false;
                    if(step>0) cout<<" ";
                    step++;
                    cout<<num;
                    num=num*3+1;
                }
                else
                {
                    num=num/2;
                }
            }
            if(flag) cout<<"No number can be output !";
            cout<<endl;
        }

    }

    return 0;
}
