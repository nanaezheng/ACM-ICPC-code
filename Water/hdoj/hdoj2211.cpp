#include <iostream>
#include <cmath>
using namespace std;

__int64 arr[110][100000];
long T, N, K;


int main()
{
    __int64 _max= 1;
    _max = _max << 32;
    for(int i=3; i<110; ++i)
    {
        arr[i][0] = i;
        for(int j=1; arr[i][j-1]<_max; ++j)
            if(arr[i][j-1] % (i-1) == 0)
                arr[i][j] = arr[i][j-1] * i/(i-1) - 1;
            else
                arr[i][j] = abs((arr[i][j-1] * i * 1.0)/(i-1));
    }
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        for(int i=0;; ++i)
            if(arr[K][i] > N)
            {
                printf("%I64d\n", arr[K][i-1]);
                break;
            }

    }
    return 0;

}
