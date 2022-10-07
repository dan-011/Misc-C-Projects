#include <stdio.h>
#include <stdlib.h>

/*
 *  Return the sum of even tribonacci numbers between 1 and max
 */
long  even_tribonacci_sum( long max )
{
    long t1 = 1;
    long t2 = 1;
    long t3 = 2;
    long sum = 0;
    while(t3 <= max){
        if(!(t3 % 2)) sum += t3;
        long tn = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = tn;
    }
    return sum;
}


// DO NOT MODIFY THE CODE BELOW

int main( void )
{
    long max;

    scanf("%ld", &max);

    printf( "%ld\n", even_tribonacci_sum( max ) );

    return 0;
}
