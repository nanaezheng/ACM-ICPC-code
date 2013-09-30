// Problem#: 2499
// Submission#: 1923417
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University

//�����һ��ѭ���ҳ�����Ϊ��ȫƽ��������Щ�������Ϊ 1 ���ڶ���ѭ����������ƽ����֮�ͣ�����ƽ����֮�͵���Щ�����Ϊ 2 ��3 ��û����ǲ����� 4 ��ƽ������ɡ�

#include <cstdio>
using namespace std;

int main()
{
    int T, N;
    int i, j;
    int data[ 60001 ];

    for ( i = 0; i <= 60000; i++ )
        data[ i ] = 4;
    for ( i = 0; i * i <= 60000; i++ )
        data[ i * i ] = 1;
    for ( i = 1; i < 60000; i++ ) {
        if ( data[ i ] == 1 ) {
            for ( j = i; i + j <= 60000; j++ ) {
                if ( data[ j ] == 1 && data[ i + j ] > 2 )
                    data[ i + j ] = 2;
                else if ( data[ j ] == 2 && data[ i + j ] > 3 )
                    data[ i + j ] = 3;
            }
        }
    }

    scanf( "%d", &T );
    while ( T-- ) {
        scanf( "%d", &N );
        printf( "%d\n", data[ N ] );
    }

    return 0;

}
