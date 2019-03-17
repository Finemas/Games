/*
 * cv06.c    v.2.0
 *
 * Aritmeticke vyrazy a operatory ++ a --
 * ======================================
 *
 */

#include <stdio.h>

int main(void)
{
  int a, b, c, d, e;

  a = 2; b = 2; c = 1; d = 0; e = 4;
  printf("a) %d\n", a++  / ++c  *  --e);

  a = 2; b = 2; c = 1; d = 0; e = 4;
  printf("b) %d\n", --b  *  c++  - a);

  a = 2; b = 2; c = 1; d = 0; e = 4;
  printf("c) %d\n", -b  -  --c);

  a = 2; b = 2; c = 1; d = 0; e = 4;
  printf("d) %d\n", ++a  -  --e);

  a = 2; b = 2; c = 1; d = 0; e = 4;
  printf("e) %d\n", e  /  --a  *  b++  / c++);

  a = 2; b = 2; c = 1; d = 0; e = 4;
  printf("f) %d\n", a %= b = d = 1 + e / 2);
  return 0;
}
