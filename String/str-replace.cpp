#include<iostream>
#include<string.h>
using namespace std;
char swap[1000],str[1000],key[1000],;
int l1,l2,l3,i,j,flag;
char tmp[1000];

void replace(char str[],char key[],char swap[])
{
    int l1,l2,l3,i,j,flag;
    char tmp[1000];
    l1=strlen(str);
    l2=strlen(key);
    l3=strlen(swap);
    for (i=0;i<=l1-l2;i++)
        {
        flag=1;
        for (j=0;j<l2;j++)
            if (str[i+j]!=key[j]) {flag=0;break;}
        if (flag)
            {
            strcpy(tmp,str);
            strcpy(&tmp[i],swap);
            strcpy(&tmp[i+l3],&str[i+l2]);
            strcpy(str,tmp);
            i+=l3-1;
            l1=strlen(str);
            }
        }
}

int main()
{
 char swap[1000];
 cin>>str>>key>>swap;
 replace( str , key,swap );
 cout<<str<<endl;
 system("Pause");
}
