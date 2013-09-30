#include <iostream>
#include <limits>
using namespace std;

const int MAXSIZE = 100;
int a[MAXSIZE][MAXSIZE],b[MAXSIZE],n;

int maxSubArray()
{//������������к�
    int curSum=0,sum=numeric_limits<int>::min();
    for(int i=0;i<n;i++)
    {
        if(curSum>0)
            curSum+=b[i];
        else
            curSum=b[i];
        if(curSum>sum)
            sum=curSum;
    }
    return sum;
}
int maxSubMatrix()
{//��������Ӿ����
    int i,j,k,curSum=0,sum=numeric_limits<int>::min();
    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)//��ʼ��b[]
        {
            b[k]=0;
        }
        for(j=i;j<n;j++)//�ѵ�i�е���j�����,��ÿһ�����������ֵ
        {
            for(k=0;k<n;k++)
            {
                b[k]+=a[j][k];
            }
            curSum=maxSubArray();
            if(curSum>sum)
            {
                sum=curSum;
            }
        }
    }
    return sum;
}

int main(void)
{
    cin>>n;
    int i,j;
    //�������
    for (i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
    cout<<maxSubMatrix()<<endl;
    return 0;
}
