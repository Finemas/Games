/*
 * s56a.c    v.2.0
 *
 * Prikaz while
 * ============
 */

#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) < 'z') {
    if (c >= ' ')
      putchar(c);               /* tisk znaku */
  }
  printf("\nCteni znaku bylo ukonceno.\n");
  return 0;
}
