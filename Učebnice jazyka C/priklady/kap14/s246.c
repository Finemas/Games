/*
 * s246.c    v.2.0
 *
 * Struktura jako parametr funkce - volani odkazem
 * ===============================================
 */

#include <stdio.h>

typedef struct {
  double re, im;
} KOMP;

void secti(KOMP *a, KOMP *b, KOMP *c)
{
  c->re = a->re + b->re;
  c->im = a->im + b->im;
}

int main(void)
{
  KOMP x, y, z;

  x.re = 1.1;  x.im = 3.14;
  y = x;
  secti(&x, &y, &z);
  printf("Re = %f, Im = %f\n", z.re, z.im);
  return 0;
}

