/*
 * Created by Jan Fineas Provaznik on 07/11/2018.
 *
 * Uživatel zadá číslo platné pozice a ASCII tabulce a program vypíše znak na dané pozici.
 */

#include <stdio.h>

int main(void)
{
    int symbol = '\0';

    printf( "Vstup: " );
    scanf( " %d", &symbol );
    if ( symbol > 127 ) {
        printf("Zadané číslo je mimo ASCII tabulku\n");
        return 1;
    }
    printf( "Výstup: %c\n", symbol );

    return 0;
}
