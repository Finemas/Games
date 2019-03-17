/*
 * s61.c    v.2.0
 *
 * Nevhodne pouzity prikaz switch
 * ==============================
 */

#include <stdio.h>

int main()
{
  switch (getchar()) {
    case 'a' :
    case 'b' :
    case 'c' : putchar('1');
    case 'd' : putchar('2');
    default  : putchar('3');
  }
  return 0;
}
