/*
 * cv01.c    v.2.0
 *
 * Definovani, pouziti a tisk symbolicke konstanty
 * ===============================================
 *
 */

#include <stdio.h>

#define N  5

int main(void)
{
  int i,
      suma = 0;

  for (i = 1;  i <= N;  i++)
    suma += i;

  printf("Soucet prvnich %d cisel je %d\n", N, suma);

  return 0;
}

