/*
 * cv01.c    v.2.0
 *
 * Typova konverze
 * ===============
 *
 */

#include <stdio.h>

int main(void)
{
  int i, j;
  float f;

  i = 5, j = 2;                 /* pouziti operatoru carky */
  f = (float) i / j;
  printf("Typova konverze - 1. moznost: %f\n", f);

  f = i / (float) j;
  printf("Typova konverze - 2. moznost: %f\n", f);

  f = (float) i / (float) j;
  printf("Typova konverze - 3. moznost: %f\n", f);

  f = (float) (i / j);
  printf("Explicitni typova konverze - chybny zpusob: %f\n", f);

  f = i / j;
  printf("Implicitni typova konverze - chybny zpusob: %f\n", f);
  return 0;
}

