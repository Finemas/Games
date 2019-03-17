/*
 * s256.c    v.2.0
 *
 * Ukazka zpusobu prace s unionem
 * ==============================
 */

#include <stdio.h>

typedef union {
  char  c;
  int   i;
  float f;
} ZN_INT_FLT;

int main(void)
{
  ZN_INT_FLT a, *p_a = &a;

  a.c = '#';
  printf("c = %c, i = %d, f = %f\n", a.c, a.i, a.f);

  p_a->i = 1;     /* premaze znak '#' */
  printf("c = %c, i = %d, f = %f\n", a.c, a.i, a.f);

  a.f = 2.3;      /* premaze cislo 1 */
  printf("c = %c, i = %d, f = %f\n", a.c, a.i, a.f);
  return 0;
}

