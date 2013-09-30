// Problem#: 8037
// Submission#: 2077505
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <cstdio>

using namespace std;

long long f(long long x)
{
        if (x <= 2) return 0;

        return (x / 2 - 1) * 5 + (x % 2) * 2
                + (x + 6) / 12
                + (x + 420) / 840
                + (x + 360360) / 720720
                + (x + 72201776446800LL) / 144403552893600LL;
}

int main()
{
        long long a, b;

        while (scanf("%lld%lld", &a, &b) != EOF)
                printf("%lld\n", f(b) - f(a - 1));

        return 0;
}
