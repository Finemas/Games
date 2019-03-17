//
// Created by Jan Fineas Provaznik on 2019-01-04.
//
#include <stdio.h>

int main() {
    int x = 0;
    char str[10];
    char fileName[] = "data.txt";
    FILE * fp;

    fp = fopen ( fileName, "r" ); /* r - pouze cteni */

    do{
        fscanf( fp, "%s", str );
        printf( "%s\n", str );
    } while( x );

    fclose ( fp );

    return 0;
}
