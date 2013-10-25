#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAX 110009
using namespace std;

int main()
{
    int i,j,num,ans;
    char str[MAX],ch;
    int  odd[MAX],even[MAX];
    while(scanf("%s",str)!=EOF)
    {
        ans = 1;
        odd[0]=1;
        even[0]=0;
        int len=strlen(str);
        for( i = 1 ; i < len ; i++ )
        {
            num=odd[i-1];
            for( j = num + 1 ; j >= 0 ;)
            {
                if( i - j  >= 0 && str[i] == str[i-j])
                {
                    odd[i] = j+1 ;
                    if( odd[i] > ans ) ans = odd[i];
                    break;
                }
                j = j - 2 ;
            }
            num = even[i-1];
            for( j = num + 1 ; j >= 0; )
            {
                if(i - j >= 0 && str[i] == str[i-j])
                {
                    even[i ] = j + 1 ;
                    if( even[i] > ans) ans = even[i];
                    break;
                }
                j = j - 2 ;
            }
            if( j == -1 ) even [i] = 0;
        }
        printf("%d\n",ans);

    }
    return 0;
}
