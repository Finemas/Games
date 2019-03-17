/*
 * s56b.c    v.2.0
 *
 * Prikazy break a continue a nekonecna smycka pomoci while
 * ========================================================
 */

#include <stdio.h>

int main()
{
  int c;

  while (1) {            /* nekonecna smycka */
    if ((c = getchar()) < ' ')
      continue;          /* zahozeni neviditelneho znaku */
    if (c == 'z')
      break;             /* zastaveni po nacteni znaku 'z' */
    putchar(c);          /* tisk znaku */
  }
  printf("\nCteni znaku bylo ukonceno.\n");
  return 0;
}
