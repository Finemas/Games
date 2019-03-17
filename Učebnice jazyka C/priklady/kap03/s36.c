/*
 * s36.c    v.2.0
 *
 * Deleni celociselne a deleni modulo
 * ==================================
 */

#include <stdio.h>

int main()
{
  int i = 5, j = 13;

  j = j / 4;
  printf("j = %d\n", j);
  j = i % 3;
  printf("j = %d\n", j);
  return 0;
}
