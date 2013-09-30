#include<iostream>
#include<string.h>
using namespace std;
char str[1000],key[1000];
int l1,l2,i,j,flag;
int strfind(char str[],char key[])
{
    
    l1=strlen(str);
    l2=strlen(key);
    for (i=0;i<=l1-l2;i++)
        {
        flag=1;
        for (j=0;j<l2;j++)
            if (str[i+j]!=key[j]) {flag=0;break;}
        if (flag) return i;
        }
    return -1;
} 



int main()
{
 long long  n;
 cin>>str>>key;
 strfind( str , key );
 cout<<i<<endl;
 system("Pause");
}
