/*
 * s38.c    v.2.0
 *
 * Prirazovaci operatory
 * =====================
 */

#include <stdio.h>

int main()
{
  int i = 4, j = 3;

  j += i;
  printf("i = %d, j = %d\n", i, j);
  j /= --i;
  printf("i = %d, j = %d\n", i, j);
  j *= i - 2;
  printf("i = %d, j = %d\n", i, j);
  return 0;
}
