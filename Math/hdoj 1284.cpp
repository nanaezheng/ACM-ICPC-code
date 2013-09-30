#include <iostream>
using namespace std;
int euler(int x);
int main()
{
    int CN,N;
    cin >> CN;
    while(CN--)
    {
        cin >> N;
        cout << euler(N) << endl;
    }
    return 0;
}
int euler(int x)
{
    int result = x;
    for(int i = 2; i * i <= x; ++i)
    {
        if( x % i == 0)
        {
            result = result * (i - 1) / i;
            while( x % i == 0 )
            {
                x /= i;
            }
        }
    }
    if( x > 1 )
    {
        result = result * ( x - 1 ) / x;
    }
    return result;
}
