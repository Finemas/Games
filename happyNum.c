//
// Created by Jan Fineas Provaznik on 2019-01-20.
//
#include <stdio.h>
#include <stdlib.h>

int pows( int a, int x )
{
    if( x == 0 ) return 1;
    return a * pows( a, x-1 );
}

int numberDigits( int number )
{
    int tmp;
    int numDigits = 0;

    tmp = number;
    while( tmp != 0 ) {
        tmp /= 10;
        ++numDigits;
    }

    return numDigits;
}

int isHappy( int number )
{
    int * inter = (int*) malloc ( 10 * sizeof(*inter) );
    int sum = 0, div;
    int numDigit = numberDigits( number );
    int index = 0;

    while(1) {
        while( numDigit != 0 ) {
            div = number % 10;
            number /= 10;
            sum += pows(div, 2);
            --numDigit;
        }

        if( sum == 1 ) {
            return 1;
        } else {
            for( int i = 0; i <= index; ++i ) {
                if( sum == inter[i] ) {
                    return 0;
                }
            }
        }

        if( index == 10 ) {
            inter = (int *) realloc (inter, 10);
        }
        inter[index] = sum;
        ++index;

        numDigit = numberDigits( sum );
        number = sum;
        sum = 0;
    }
}

int main(void)
{
    int number;

    printf( "Zadejte cislo: " );
    scanf( " %d", &number );

    if( isHappy( number ) ) {
        printf( "Cislo %d je stastne.\n", number );
    } else {
        printf( "Cislo %d neni stastne.\n", number );
    }

    return 0;
}
