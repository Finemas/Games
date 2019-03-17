//
// Created by Jan Fineas Provaznik on 2018-12-27.
//

#include <stdio.h>

int main(void)
{
    int a, *p_a;
    a = 56;

    p_a = &a; // Uloží do p_a adresu proměnné a
    *p_a = 15; // Uloží hodnotu 15 na adresu v p_a

    printf("Ukazatel p_a má hodnotu %d ukazuje na hodnotu %d\n", p_a, *p_a);

    return 0;
}
