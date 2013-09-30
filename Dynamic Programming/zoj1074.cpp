#include <iostream>
#include <limits>
using namespace std;

const int MAXSIZE = 100;
int a[MAXSIZE][MAXSIZE],b[MAXSIZE],n;

int maxSubArray()
{//计算最大子序列和
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
{//计算最大子矩阵和
    int i,j,k,curSum=0,sum=numeric_limits<int>::min();
    for(i=0;i<n;i++)
    {
        for(k=0;k<n;k++)//初始化b[]
        {
            b[k]=0;
        }
        for(j=i;j<n;j++)//把第i行到第j行相加,对每一次相加求出最大值
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
    //输入矩阵
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
