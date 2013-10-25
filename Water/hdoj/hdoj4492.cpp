#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char str[100];
int main()
{
    int T;
    int D;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%*c",&D);
        printf("%d ",D);
        cin.getline(str,100);
        int len=strlen(str);
        int n;
        int t=0;
        scanf("%d",&n);
        int x;
        while(n--)
        {
            scanf("%d",&x);
            t+=x;
            t=(t+len)%len;
            printf("%c",str[t]);
        }
        printf("\n");
    }
    return 0;
}
