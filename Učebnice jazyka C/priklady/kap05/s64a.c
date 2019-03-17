/*
 * s64a.c    v.2.0
 *
 * Prikaz break v prepinaci switch - vhodne pouziti
 * ================================================
 */

#include <stdio.h>

int main()
{
  char c;

  while ((c = getchar()) != '*') {
    switch (c) {
      case ' '  :
      case '\t' :
        putchar('#');
        break;

      default   :
        putchar(c);
        break;
    }
  }
  return 0;
}
