#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    double n,m;
    cout << setiosflags(ios_base::fixed) << setprecision(2);
    while(cin >> n >> m)
    {
        cout << 1/n <<endl;
    }
    return 0;
}
