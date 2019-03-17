/*
 * cv06.c    v.2.0
 *
 * Definice komplikovaneho makra
 * =============================
 *
 */

#include <stdio.h>

#define cti_int(i)  (scanf("%d", &i), i)

int main(void)
{
  int j, k;

  printf("Zadej cele cislo: ");
  if ((j = cti_int(k)) == 0)
    printf("Byla nactana nula: j = %d, k = %d\n", j, k);
  else
    printf("Nactena cisla: j = %d, k = %d\n", j, k);

  return 0;
}

