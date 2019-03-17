/*
 * s62.c    v.2.0
 *
 * Spravne pouzity prikaz switch
 * =============================
 */

#include <stdio.h>

int main()
{
  switch (getchar()) {
    case 'a' :
    case 'b' :
    case 'c' :
      putchar('1');
      break;

    case 'd' :
      putchar('2');
      break;

    default  :
      putchar('3');
      break;
  }
  return 0;
}
