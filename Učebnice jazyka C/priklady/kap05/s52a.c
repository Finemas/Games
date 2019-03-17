/*
 * s52a.c    v.2.0
 *
 * Ternarni operator jako skutecny parametr funkce - prirazeni je vyraz
 * ====================================================================
 */

#include <stdio.h>

int main()
{
  int c, d;

  c = getchar();
  putchar(c < (d = getchar()) ? c : d);
  return 0;
}
