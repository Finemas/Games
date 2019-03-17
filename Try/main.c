//
// Created by Jan Fineas Provaznik on 2019-01-22.
//

#include <stdio.h>
#include <stdlib.h>

int scan( char array[][10], int * p_maxSize )
{
    char sym;
    int maxSize = *p_maxSize;
    int i = 0, j = 0;

    for( i = 0; i < maxSize; ++i ) {
        for( j = 0; j <= maxSize; ++j ) {
            if( scanf("%c", &sym) != 1 ) {
                printf("Nespravny vstup.\n");
                return 0;
            }
            if( sym == '\n' || j == 10 ) {
                if( i == 0 ) maxSize = j;
                break;
            } else {
                array[i][j] = sym;
            }
        }
    }

    *p_maxSize = maxSize;
    return 1;
}

int scans( char words )
{
    char sym;


    scanf( "%s", words );
}

void print( char array[][10], int maxSize )
{
    int k, l;

    for( k = 0; k < maxSize; ++k ) {
        for( l = 0; l < maxSize; ++l ) {
            printf( "%c", array[k][l] );
        }
        printf( "\n" );
    }
}

int main()
{
    char array[10][10];
    char * words = (char*) calloc ( 10, sizeof(*words) );
    int maxSize;

    scan( array, &maxSize );
    scans( words );

    print( array, maxSize );

    return 0;
}
