#include <iostream>
using namespace std;

int qmod (int a, int b, int c)	//快速取幂模公式
{
    int t;
    if (b == 1)
        return a;
    t = qmod (a, b / 2, c);		//分解
    t = t * t % c;			//分解到最小进行综合求解
    if (b % 2)
        t = t * a % c;
    if (!t)			//余数为0，结果应该为9
        t = c;
    return t;
}

int main()
{
    int n;
    while (cin >> n, n)
        cout << qmod (n, n, 9) << endl;	//数学问题
    return 0;
}


