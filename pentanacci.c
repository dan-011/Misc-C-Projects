#include <stdio.h>

/*
 *  Return the sum of all even Pentanacci numbers between 1 and max
 */
long  even_pentanacci_sum( long max )
{
    long sum = 0;
    long p1 = 0;
    long p2 = 0;
    long p3 = 0;
    long p4 = 1;
    long p5 = 2;
    while(p5 < max){
        if(!(p5 % 2)) sum += p5;
        long cur = (2*p5) + (3*p4) + (3*p3) + p2 + 3*p1;
        p1 = p2;
        p2 = p3;
        p3 = p4;
        p4 = p5;
        p5 = cur;
    }
    return sum;
}



// DO NOT MODIFY THE CODE BELOW

int main( void )
{
    long max;

    scanf("%ld", &max);

    printf( "%ld\n", even_pentanacci_sum( max ) );

    return 0;
}
