/*
 * Created by Jan Fineas Provaznik on 07/11/2018.
 *
 * Uživatel zadá znak z ASII tabulky a program vypíše další znak (o jeden vyšší) a jeho kod.
 */

#include <stdio.h>

int main(void)
{
    char symbol;

    printf( "Zadej znak: " );
    scanf( " %c", &symbol );
    printf( "Následující nak v ASCII je %c (ASCII %d)\n", symbol + 1, symbol + 1 );

    return 0;
}
