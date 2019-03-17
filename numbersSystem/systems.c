//
// Created by Jan Fineas Provaznik on 2019-01-15.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    char ch;
    int ich;
} SYSTEM;

void hello( long long int * p_number, int * p_base1, int * p_base2 )
{
    long long int number = *p_number;
    int base1 = *p_base1;
    int base2 = *p_base2;

    printf( "Zadejte z a do jake ciselne soustavy chcete prevadet: " );
    if( scanf( " %d %d", &base1, &base2 ) != 2 || ( base1 < 2 || base1 > 36 )
                                               || ( base2 < 2 || base2 > 36 ) ){
        printf( "Nespravny vstup.\n" );
    }

    printf( "Zadejte cislo, ktere chcete prevest: " );
    if( scanf( " %lld", &number ) != 1 || (number < 0 || number > 4294967296) ) {
        printf( "Nespravny vstup.\n" );
    }

    *p_number = number;
    *p_base1 = base1;
    *p_base2 = base2;
}

int numberDigits( long long int number )
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

void printLessBase( int * res, int number, int base2, int i )
{
    printf( "Cislo %d v %d soustave je ", number, base2 );

    for( int j = i; j >= 0; --j) {
        printf( "%d", res[j] );

    }
    printf( "\n" );
}

long long int pows( int a, int x )
{
    if( x == 0 ) return 1;

    return a * pows( a, --x );
}

int systemTableInt( int binary )
{
    switch( binary ) {
        case 0: return 0;
        case 1: return 1;
        case 10: return 2;
        case 11: return 3;
        case 100: return 4;
        case 101: return 5;
        case 110: return 6;
        case 111: return 7;
    }

    switch( binary ) {
        case 1000: return 8;
        case 1001: return 9;
    }

    return 20;
}

char systemTableChar( int binary )
{
    switch (binary) {
        case 1010:
            return 'A';
        case 1011:
            return 'B';
        case 1100:
            return 'C';
        case 1101:
            return 'D';
        case 1110:
            return 'E';
        case 1111:
            return 'F';
        case 10000:
            return 'G';
        case 10001:
            return 'H';
        case 10010:
            return 'I';
        case 10011:
            return 'J';
        case 10100:
            return 'K';
        case 10101:
            return 'L';
        case 10110:
            return 'M';
        case 10111:
            return 'N';
        case 11000:
            return 'O';
        case 11001:
            return 'P';
        case 11010:
            return 'Q';
        case 11011:
            return 'R';
        case 11100:
            return 'S';
        case 11101:
            return 'T';
        case 11110:
            return 'U';
        case 11111:
            return 'V';
        case 100000:
            return 'W';
        case 100001:
            return 'X';
        case 100010:
            return 'Y';
        case 100011:
            return 'Z';
        default:
            return 1;
    }
}

/* SYSTEM * hex( int res, int i )
{
    SYSTEM ** number = (SYSTEM*) malloc ( 10 * sizeof( *number ) );
    int div = i % 4;
    int binary = 0;
    int tmp;
    int index = 0;

    while( i != div ) {
        for( int j = 1; j <= 1000 ; j*=10) {
            tmp = res[i];
            binary += j * tmp;
        }
    }


} */

int * lessBase( int * res, int number, int base1, int base2, int * p_i )
{
    int tmp = number;
    int i = *p_i;

    while(1) {
        res[i] = tmp % base2;
        if( (tmp /= base2) == 0 ) break;
        ++i;
    }
    *p_i = i+1;

    return res;
}

long long int moreBase( long long int number, int base1, int base2, int numDigits )
{
    int tmp = number;
    int div = 0;
    int sum = 0;

    for( int i = 0; i < numDigits; ++i ) {
        div = tmp % 10;
        sum += (div * (pows( base1, i )) ) ;
        tmp /= 10;
    }

    return sum;
}

SYSTEM * newNumber( SYSTEM * numbers, char chr, int it, int k )
{
    if( chr != '\0' ) {
        numbers[k].ch = (char**) calloc ( 5, sizeof( **numbers ) );
        numbers[k].ch = chr;
        numbers[k].ich = 2;
    } else {
        numbers[k].i = it;
        numbers[k].ich = 1;
    }

    return numbers;
}

int main()
{
    //long long int number;
    int * res = (int*) malloc ( 20 * sizeof( *res ) );
    //int base1, base2;
    //int numDigits;
    int tmp;

    res[0] = 1;
    res[1] = 0;
    res[2] = 0;
    res[3] = 1;
    res[4] = 1;

    SYSTEM numbers[100];
    int i = 5;
    int binary = 0;
    int k = 0;
    char chr = '\0';
    int div = i % 5;

    while( i != div ) {
        for( int j = 1; j <= 1000 ; j*=10) {
            tmp = res[i];
            binary += j * tmp;
        }
        chr = systemTableChar( binary );
        if( chr != 1 ) {
            newNumber( numbers, chr, 666, k );
            ++k;
        } else {
            newNumber( numbers, chr, binary, k );
            ++k;
        }
        ++i;
    }

    for( int l = 0; l <= k; ++l ) {
        if( numbers[l].ich == 1 ) {
            printf( "%d", numbers[l].i );
        } else {
            printf( "%c", numbers[l].ch );
        }
    }

    printf( "\n" );

    //hello( &number, &base1, &base2 );

    /* if( base1 < 10 && base2 < 10 ) {
        if( base1 > base2 ) {
            lessBase( res, number, base1, base2, &i );
            printLessBase( res, number, base2, i );
        } else if( base1 < base2 ) {
            numDigits = numberDigits( number );
            moreBase( number, base1, base2, numDigits );
            printf( "Cislo %lld v %d soustave je %lld\n", number, base2, moreBase( number, base1, base2, numDigits ) );
        } else {
            printf( "Cislo %lld v %d soustave je %lld", number, base1, number );
        }
    } else if( base1 < 16 && base2 < 16 ) {
        if( base1 > base2 ) {
            lessBase( number, base1, 2, &i );

        } else if( base1 < base2 ) {
            numDigits = numberDigits( number );
            moreBase( number, base1, base2, numDigits );
            printf( "Cislo %lld v %d soustave je %lld\n", number, base2, moreBase( number, base1, base2, numDigits ) );
        } else {
            printf( "Cislo %lld v %d soustave je %lld", number, base1, number );
        }
    } else if( base1 < 32 && base2 < 32 ) {

    } else {

    } */

    free(res);

    return 0;
}
