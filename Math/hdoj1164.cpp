#include <iostream>
using namespace std;

int qmod (int a, int b, int c)	//����ȡ��ģ��ʽ
{
    int t;
    if (b == 1)
        return a;
    t = qmod (a, b / 2, c);		//�ֽ�
    t = t * t % c;			//�ֽ⵽��С�����ۺ����
    if (b % 2)
        t = t * a % c;
    if (!t)			//����Ϊ0�����Ӧ��Ϊ9
        t = c;
    return t;
}

int main()
{
    int n;
    while (cin >> n, n)
        cout << qmod (n, n, 9) << endl;	//��ѧ����
    return 0;
}


