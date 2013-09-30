// Problem#: 7970
// Submission#: 2040057
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char ch[10000];
int n, m;

int main()
{
	int Case;	scanf( "%d", &Case );

	while( Case-- ) {
		n = 0;	char temp = getchar();
		memset( ch,0,sizeof(ch) );

		scanf( "%s", ch );

		n = strlen(ch);
		m = sqrt(n);

		for( int i = 0; i < m; i++ ) {
			for( int j = m-i-1; j < n; j+=m ) {
				putchar( ch[j] );
			}
		}
		putchar(10);
	}

	return 0;
}
