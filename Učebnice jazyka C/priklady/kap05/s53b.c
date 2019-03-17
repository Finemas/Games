/*
 * s53b.c    v.2.0
 *
 * Prikaz if s vyuzitim prirazeni - Pozor: zamerna chyba !!!
 * =========================================================
 */

#include <stdio.h>

int main()
{
  int c;

  if (c = getchar() >= 'A'  &&  c <= 'Z')     /* zde je chyba */
    printf("%d\n", c);
  return 0;
}
