//
// Created by Jan Fineas Provaznik on 2018-12-27.
//

#include <stdio.h>

int main(void)
{
    int a;
    a = 56;
    printf("Proměnná a s hodnotou %d je v paměti uložená na adrese %p\n", a, &a);


    /* int i, *p_i;

    i = 3;

    p_i = i;
    printf( "%d\n", p_i );
    p_i = &i;
    printf( "& %d\n", p_i );
    *p_i = i;
    printf( "* %d\n", *p_i );
    *p_i = &i;
    printf( "*& %d\n", *p_i ); */



    /*printf( "i = %d, p_i = %d\n", i, p_i);
    printf( "* i = %d, p_i = %d\n", i, *p_i);
    i = *p_i;
    printf( "i = %d, p_i = %d\n", i, p_i);
    printf( "* i = %d, p_i = %d\n", i, *p_i);
    *p_i = i;
    printf( "i = %d, p_i = %d\n", i, p_i);
    printf( "* i = %d, p_i = %d\n", i, *p_i);
    p_i = &i;
    printf( "i = %d, p_i = %d\n", i, p_i);
    printf( "* i = %d, p_i = %d\n", i, *p_i);*/

    return 0;
}
