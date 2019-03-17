/*
 * s50b.c    v.2.0
 *
 * Ternarni operator v prirazeni
 * =============================
 */

#include <stdio.h>

int main()
{
  int i, k, j = 2;

  i = (j == 2) ? 1 : 3;
  printf("i = %d\n", i);

  k = (i > j) ? i : j;
  printf("k = %d\n", k);
  return 0;
}
