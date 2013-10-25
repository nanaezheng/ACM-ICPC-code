#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m,n;
    while (cin>>m>>n)
    {
        int result=0,max,min;
        //①此处最为关键，因为题目中并未指明输入大的在前
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
            //②最终的终止未计算在内，所以需要+1
            count++;
            if (count>result)
                result=count;
        }
        cout<<m<<" "<<n<<" "<<result<<endl;
    }
}
