#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m,n;
    while (cin>>m>>n)
    {
        int result=0,max,min;
        //�ٴ˴���Ϊ�ؼ�����Ϊ��Ŀ�в�δָ����������ǰ
        if(m<=n)
        {
            min=m;
            max=n;
        }
        else
        {
            min=n;
            max=m;
        }
        for(int i=min; i<=max; i++)
        {
            int count=0;
            int temp=i;
            while(temp!=1)
            {
                count++;
                if(temp%2)
                    temp=3*temp+1;
                else
                    temp=temp/2;
            }
            //�����յ���ֹδ�������ڣ�������Ҫ+1
            count++;
            if (count>result)
                result=count;
        }
        cout<<m<<" "<<n<<" "<<result<<endl;
    }
}
