/*
 * s63b.c    v.2.0
 *
 * Prikazy break a continue v prepinaci switch - nevhodne pouziti
 * ==============================================================
 */

#include <stdio.h>

int main()
{
  int c = 0;

  while (c != '*') {
    switch (c = getchar()) {
      case ' '  :
      case '\t' :
        putchar('#');
        continue;

      case '*'  :
        break;

      default   :
        putchar(c);
        break;
    }                           /* konec switch */
  }                             /* konec while */
  return 0;
}

