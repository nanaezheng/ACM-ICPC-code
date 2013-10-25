// Problem#: 7972
// Submission#: 2040363
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <iomanip>
#include <vector>

const int X = 150;

using namespace std;

int main ()
{
    double res;
    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> x(n);
        vector<double> p(n);
        for (int i=0; i<n; i++)
        {
            cin >> x[i] >> p[i];
            p[i] /= 100;
        }

        vector<double> best(X+1, 0);
        best[0] = 1;

        for (int i=0; i<n; i++)
            for (int j=X; j>=x[i]; j--)
                best[j] = max(best[j], best[j-x[i]] * p[i]);

        res=0;

        for (int i=X/2+1; i<=X; i++)
            res = max(res, best[i]);

        cout<<setprecision(10)<<100*res<<endl;
    }

    return 0;
}
