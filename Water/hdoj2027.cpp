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
    char all[]={'a','e','i','o','u'};
    while(cin>>t)
    {
        cin.get();
        while(t--)
        {
            string str;
            getline(cin,str);
            int a,b,c,d,e;
            a=b=c=d=e=0;
            for(int i=0;i<str.length();i++)
            {
                char o=str.at(i);
                if(o=='a') a++;
                else if(o=='e') b++;
                else if(o=='i') c++;
                else if(o=='o') d++;
                else if(o=='u') e++;
            }
            for(int i=0;i<5;i++)
            {
                cout<<all[i]<<":";
                if(i==0) cout<<a;
                else if(i==1) cout<<b;
                else if(i==2) cout<<c;
                else if(i==3) cout<<d;
                else if(i==4) cout<<e;
                cout<<endl;
            }
            if(t>0)
                cout<<endl;
        }
    }

    return 0;
}
