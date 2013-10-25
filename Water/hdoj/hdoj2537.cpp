#include"stdio.h"
int main()
{
    int n;
    int count1,count2;            //前者记录红球，后者记录黄球球。
    int d1,d2;
    char x;
    int i;
    while(scanf("%d",&n),n)
    {
        count1=count2=0;
        getchar();
        d1=d2=0;


        for(i=0;i<n;i++)
        {
            scanf("%c",&x);
            if(x=='Y')
                count2++;
            else if(x=='R')
                count1++;
            else if(x=='B')
                d1=1;
            else if(x=='L')
                d2=1;
        }


        if(count1!=7&&d1==1)
            printf("Yellow\n");
        else if(count2!=7&&d2==1)
            printf("Red\n");
        else if(count1==7&&d1==1)
            printf("Red\n");
        else if(count2==7&&d2==1)
            printf("Yellow\n");
    }
    return 0;
}
