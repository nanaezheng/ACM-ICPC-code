#include <stdio.h>
#include <string.h>
int main()
{
    char ch[10001];
    while(gets(ch) != NULL)
    {
        char ch1[10001];
        strcpy(ch1, ch);
        char str[101][101];
        memset(str, 0, sizeof(str));
        int a1[100001];
        int a2[100001];
        int num[10001];
        memset(num, 0, sizeof(num));
        int sum = 0;
        int h = 0, m = 0;
        while(1)
        {
            int flag = 0;
            memset(a1, 0, sizeof(a1));
            memset(a2, 0, sizeof(a2));
            int lenth = strlen(ch);
            for(int i = lenth - 1; i >= 0; i--)
            {
                a1[lenth - i] = ch[i] - '0';
            }
            for(int i = 0; i < lenth; i++)
            {
                a2[i + 1] = ch[i] - '0';
            }
            memset(ch, 0, sizeof(ch));
            int j = 0;
            for(int i = 1; i <= lenth; i++)
            {
                a2[i] = a1[i] + a2[i];
                if(a2[i] >= 10)
                {
                    if(i == lenth)
                    {
                        lenth++;
                    }
                    a2[i] = a2[i] - 10;
                    ch[j] = a2[i] + '0';
                    str[h][m] = a2[i] + '0';
                    j++;
                    m++;
                    a1[i+1]++;
                }
                else
                {
                    ch[j] = a2[i] + '0';
                    str[h][m] = a2[i] + '0';
                    m++;
                    j++;
                }
            }
            sum++;
            num[h] = m;
            for(int i  = 0; i < j / 2; i++)
            {
                if(ch[i] != ch[j - i - 1])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                break;
            }
            else
            {
                h++;
                m = 0;
            }
        }
        printf("%d\n",sum);
        printf("%s--->",ch1);
        for(int i = 0; i < sum; i++)
        {
            for(int j = num[i] - 1; j >= 0; j--)
            {
                printf("%c",str[i][j]);
            }
            if(i != sum - 1)
            {
                printf("--->");
            }
        }
        printf("\n");
    }
    return 0;
}
