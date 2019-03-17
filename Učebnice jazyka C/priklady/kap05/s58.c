/*
 * s58.c    v.2.0
 *
 * Cyklus do-while
 * ===============
 */

#include <stdio.h>

int main()
{
  int c;

  do {
    if ((c = getchar()) >= ' ')
      putchar(c);               /* tisk znaku */
  } while (c != 'z');
  return 0;
}
