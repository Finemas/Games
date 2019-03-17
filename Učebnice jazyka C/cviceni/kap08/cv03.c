/*
 * cv03.c    v.2.0
 *
 * Definice vlastnich maker pro matematicke vypocty
 * ================================================
 *
 */

#include <stdio.h>

#define na_treti(x)  ((x) * (x) * (x))

int main(void)
{
  int i = 2,
      j = 3;

  printf("Cislo %d na treti %d\n", 3, na_treti(3));
  printf("Cislo %d na treti %d\n", i, na_treti(i));
  printf("Cislo %d na treti %d\n", 2 + 3, na_treti(2 + 3));
  printf("Cislo %d na treti %d\n", i * j + 1, na_treti(i * j + 1));
  return 0;
}

