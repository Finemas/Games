/*
 * s51c.c    v.2.0
 *
 * Ternarni operator jako skutecny parametr funkce
 * ===============================================
 */

#include <stdio.h>

int main()
{
  int c, d;

  c = getchar();
  d = getchar();
  putchar(c < d ? c : d);
  return 0;
}
