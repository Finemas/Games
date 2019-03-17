/*
 * s245.c    v.2.0
 *
 * Struktura jako parametr funkce - volani hodnotou
 * ================================================
 */

#include <stdio.h>

typedef struct {
  double re, im;
} KOMP;

KOMP secti(KOMP a, KOMP b)
{
  KOMP c;

  c.re = a.re + b.re;
  c.im = a.im + b.im;
  return c;
}

int main(void)
{
  KOMP x, y, z;

  x.re = 1.1;  x.im = 3.14;
  y = x;
  z = secti(x, y);
  printf("Re = %f, Im = %f\n", z.re, z.im);
  return 0;
}

