//
// Created by Jan Fineas Provaznik on 2019-01-22.
//
#include <stdio.h>

#define MAX 10

void full( int * array )
{
    for( int i = 0; i < MAX; ++i ) {
        array[i] = i;
    }
}

int main(void)
{
    int array[MAX];

    //full( array );

    for( int i = 0; i < MAX; ++i ) {
        printf( "%d", array[i] );
    }
    printf("\n");

    return 0;
}
