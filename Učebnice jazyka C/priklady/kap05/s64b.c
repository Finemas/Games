/*
 * s64b.c    v.2.0
 *
 * Prikaz break v prepinaci switch - prilis zkracena verze
 * =======================================================
 */

#include <stdio.h>

int main()
{
  char c;

  while ((c = getchar()) != '*') {
    switch (c) {
      case ' '  :
      case '\t' :
        c = '#';
      default   :
        putchar(c);
    }
  }
  return 0;
}
