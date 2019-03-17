/*
 * s51a.c    v.2.0
 *
 * Prevod velkych pismen na mala
 * =============================
 */

#include <stdio.h>

int main()
{
  char c = 'B';

  c = (c >= 'A'  &&  c <= 'Z')  ?  c + ('a' - 'A')  :  c;
  printf("c = %c\n", c);
  return 0;
}
