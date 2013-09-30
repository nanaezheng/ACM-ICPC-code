#include <stdio.h>


int n, num[100010] ;
int Sum, Start, End ;


void Find ()
{
    int i, buff = 0, all_below_0 = 0 ;
    int start_buff ;
    start_buff = Sum = Start = End = 0 ;
    for (i = 0 ; i < n ; i++)
    {
        if (num[i] >= 0) all_below_0 = 1 ;

        buff += num[i] ;
        if (buff > Sum)
        {
            Sum = buff ;
            End = i ;
            Start = start_buff ;
        }
        if (buff < 0)
        {
            buff = 0 ; start_buff = i + 1 ;
            continue ;
        }
    }

    if (all_below_0 == 0)//如果都是负数
    for (i = 1, Sum = all_below_0 = num[Start = End = 0] ; i < n ; i++)
        if (num[i] > all_below_0)
        {
            Start = End = i ;
            Sum = all_below_0 = num[i] ;
        }

}


int main ()
{
    int T, i, j ;
    scanf ("%d", &T) ;
    for (i =1 ; i <= T ; i++)
    {
        scanf ("%d", &n) ;
        for (j = 0 ; j < n ; j++)
            scanf ("%d", num + j) ;
        Find () ;
        printf ("Case %d:\n", i) ;
        printf ("%d %d %d\n", Sum, Start + 1, End + 1) ;
        if (i != T) printf ("\n") ;
    }
    return 0 ;
}
