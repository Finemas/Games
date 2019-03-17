/*
 * Created by Jan Fineas Provaznik on 07/11/2018.
 *
 * Uživatel zadá číslo v dekadické soustavě v rozsahu 0 až 255 a program ho vypíše hexadecimální soustavě.
 */

#include <stdio.h>

int main(void)
{
    int number;

    printf( "Zadejte dekadicke cislo v rozsahu 0 .. 255: " );
    scanf( " %d", &number );
    if ( number > 255 || number < 0) {
        printf( "--------------------------------------------------\n"
                "Zadané číslo není v intervalu <0;255>\n");
        return 1;
    }
    printf( "Hexadecimální soustava: %2Xh \n", number );

    return 0;
}

