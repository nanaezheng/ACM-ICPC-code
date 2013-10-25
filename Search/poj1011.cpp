#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, num[65], sum, vis[65];

bool compare(const int& a, const int& b)
{
    return a > b;
}

bool dfs(int id, int fac, int rest, int next)
{
    if (rest == 0)
    {
        id++;
        rest = fac;
        next = 1;
    }
    if (id > sum / fac)
    {
        return true;
    }
    for (int i = next; i <= n; i++)
    {
        if (!vis[i])
        {
            if (rest >= num[i])
            {
                vis[i] = true;
                if (dfs(id, fac, rest-num[i], i+1))
                    return true;
                vis[i] = false;
                if (rest == fac)
                    return false;
                if (rest == num[i])
                    return false;
                while (num[i] == num[i+1])
                    i++;
            }
        }
    }
    return false;
}

int main()
{
    while (cin>>n)
    {
        sum = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            cin>>num[i];
            sum += num[i];
        }
        sort(num + 1, num + n + 1, compare);
        for (int x = 1; x <= sum; x++)
        {
            if (!(sum % x))
            {
                if (dfs(1, x, x, 1))
                {
                    cout<<x<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
