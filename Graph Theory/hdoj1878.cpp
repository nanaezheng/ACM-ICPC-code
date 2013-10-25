#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef struct
{
    int parent;
}Node;

Node nodes[1005];
int degree[1005];


int finds(int node)
{
    int p = node;
    while(nodes[p].parent)
        p = nodes[p].parent;
    return p;
}

void unions(int ra, int rb)
{
    nodes[rb].parent = ra;
}

int main()
{
    int i, n, m;
    int na, nb, ra, rb;
    int count, ok;
    while(cin>>n&&(n!=0))
    {
        cin>>m;
        memset(nodes, 0, sizeof(Node)*(n+1));
        memset(degree, 0, sizeof(int)*(n+1));
        count = n-1;
        for(i = 0; i < m; i++)
        {
            cin>>na>>nb;

            degree[na]++;
            degree[nb]++;

            ra = finds(na);
            rb = finds(nb);

            if(ra != rb)
            {
                count--;
                unions(ra,rb);
            }
        }
        ok = 1;
        if(count)
            ok = 0;
        else
        {
            for(i = 1; i <= n; i++)
                if(degree[i] % 2)
                {
                    ok = 0;
                    break;
                }
        }
        printf("%d\n", ok ? 1 : 0);
    }
    return 0;
}
