/*
 * Created by Jan Fineas Provaznik on 07/11/2018.
 *
 * Program vypíše částku s daní, to jest plus 25%.
 */

#include <stdio.h>

int main(void)
{
    int castka;

    printf( "Zadeje částku: " );
    scanf( " %d", &castka );
    printf( "Prodejni cena s daní: %.2f Kč\n", castka * 1.25 );

    return 0;
}
