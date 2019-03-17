//
// Created by Jan Fineas Provaznik on 2019-01-23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void* a, const void* b)
{
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;

    if( arg1 < arg2 ) return -1;
    if( arg1 > arg2 ) return 1;
    return 0;
}


int main(void)
{
    char array[9] = "muha";
    char array1[9] = "ahoj";
    char array2[9] = "aaaaa";

    qsort( array, 9, sizeof(char), compare_ints );

    for( int i = 0; i < 9; ++i ) {
        printf( "%c\n", array[i] );
    }

    return 0;
}
