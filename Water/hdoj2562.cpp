#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    char str[55];
    int i,t ,n;
    cin>>t;
    while(t--)
    {
        cin>>str;

        for(i=0; i<strlen(str); i=i+2)
            swap(str[i], str[i+1]);
        cout << str << endl;
    }
    return 0;
}
