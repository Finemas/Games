/*
 * cv10.c    v.2.0
 *
 * Cisteni bufferu klavesnice
 * ==========================
 *
 */

#include <stdio.h>

int main(void)
{
  int c, i = 1;

  for ( ; ; ) {                 /* nekonecny cyklus */
    printf("%d\n", i++);
    if (i % 10 == 0) {
      printf("Mam pokracovat ? [A / N]: ");
      c = getchar();
      while (getchar() != '\n')
        ;
      if (c == 'n'  ||  c == 'N')
        break;
    }
  }

  return 0;
}

