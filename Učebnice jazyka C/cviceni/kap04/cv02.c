/*
 * c02.c    v.2.0
 *
 * Cteni a tisk znaku
 * ==================
 *
 */

#include <stdio.h>

int main(void)
{
  int c;

  printf("Zadej znak: ");
  c = getchar() + 1;
  printf("%c (ASCII %d)\n", c, c);
  return 0;
}

