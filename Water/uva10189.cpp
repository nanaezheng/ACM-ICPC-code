#include<iostream>
#include<cstring>
#define max 108
using namespace std;
char str[max][max];
char st[max][max];
int row=0,line=0;
int count=0;
void reju(int a)
{
    int sum=0;
    for(int m=1; m<=row; m++)
        for(int n=1; n<=line; n++)
        {
            if(str[m][n]=='*')
                st[m][n]='*';
            if(str[m][n]=='.')
            {
                if(str[m][n+1]=='*')
                    sum++;
                if(str[m+1][n]=='*')
                    sum++;
                if(str[m][n-1]=='*')
                    sum++;
                if(str[m-1][n]=='*')
                    sum++;
                if(str[m+1][n+1]=='*')
                    sum++;
                if(str[m+1][n-1]=='*')
                    sum++;
                if(str[m-1][n-1]=='*')
                    sum++;
                if(str[m-1][n+1]=='*')
                    sum++;
                st[m][n]=sum+'0';
            }
            sum=0;
        }
    cout<<"Field #"<<count<<":"<<endl;
    for(int p=1; p<=row; p++)
    {
        for(int q=1; q<=line; q++)
            cout<<st[p][q];
        cout<<endl;
    }
}
int main()
{
    cin>>row>>line;
    while(row!=0&&line!=0)
    {
        count++;
        memset(str,'.',108*108);
        memset(st,'.',108*108);
        for(int m=1; m<=row; m++)
            for(int n=1; n<=line; n++)
                cin>>str[m][n];
                if(count>1)//����2�����ݲŻ��п���
            cout<<endl;//������������֮���ж϶���Ϊ0�ǣ���ȷ�����������ʱ�����ܼӿ���
        reju(2);
        cin>>row>>line;
    }
    return 0;
}
