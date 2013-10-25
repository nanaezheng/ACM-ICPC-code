#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,i,j;
	int data[40000];
	for(i=0; i<40; i++)
		data[i] = i;
	while(cin>>n, n)
	{

		for(i=1; i<=n; i++)
		{
			cout << setw(3) <<data[i];
		}
		cout << endl;
		int a=4*(n-1);
		int b=n+1;
		for(i=1; i<=n-2; i++)
		{
			cout << setw(3) << data[a--];
			for(j=0; j<n-2; j++)
				cout << setw(3) << " ";
			cout << setw(3) << data[b++] << endl;
		}
		for(i=a; i>=b; i--){
			cout << setw(3) << data[i];
		}
		cout << endl;

	}
	return 0;
}
