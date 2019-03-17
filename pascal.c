//
// Created by Jan Fineas Provaznik on 2019-01-20.
//
#include <stdio.h>

void pascalTriangle( int rows )
{
    int sum = 0;
    int
    int one = 1;

    for( int i = 0; i < rows; ++i ) {
        printf( "%d ", one );
        for( int j = i; j > 0; --j ) {
            if( sum <= j ) {
                sum += one;
            } else {
                sum -= one;
            }
            printf( "%d ", sum );
        }
        printf( "\n" );
    }
}

int main(void)
{
    int rows;

    printf( "Zadejte pocet radek pascalova trojuhelniku: " );
    scanf( " %d", &rows );

    pascalTriangle( rows );

    return 0;
}
