//
// Created by Jan Fineas Provaznik on 2019-01-04.
//
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int x = 0;
    char str[10];
    char * fileName = (char *)argv[2];
    FILE * fp;
    if (argv[1] == NULL) {
        return 0;
    }

    if (strcmp(argv[1], "w") == 0) {
        fp = fopen ( fileName, "w" ); /* w - pouze zapis, prepsani existujiciho souboru! */
        printf( "Napis slovo, konec nula\n" );

        do{
            scanf( "%s", str );
            fprintf( fp, "%s", str );
        } while( x );

    } else {
        fp = fopen ( fileName, "r" ); /* w - pouze cteni */

        do{
            fscanf( fp, "%s", str );
            printf( "%s\n", str );
        } while( x );

    }



    fclose ( fp );

    return 0;
}
