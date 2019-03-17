//
// Created by Jan Fineas Provaznik on 2019-01-20.
//
#include <stdio.h>

float zaokrouhli( double cislo, double presnost )
{
    return ((long int)(cislo / presnost + 0.5)) * presnost;
}

int main(void)
{
    int a, b;
    int tmp;
    int gcd;
    float lcm;
    int prod;

    printf( "Zadejte dve cisla: " );
    scanf( " %d %d", &a, &b );


    if( a < b ) {
        tmp = a;
        a = b;
        b = tmp;
    }

    while( b > 0 ) {
        prod = a * b;
        tmp = a % b;
        a = b;
        b = tmp;
        gcd = a;
        lcm = prod / gcd;
    }

    printf( "Nejvetsi delitel je %d\n", gcd );
    printf( "Nejmensi spolecny nasobek je %f\n", lcm );

    return 0;
}
