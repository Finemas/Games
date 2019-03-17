/*
 * s52b.c    v.2.0
 *
 * Prikaz if
 * =========
 */

#include <stdio.h>

int main()
{
  int c;

  c = getchar();
  if (c >= 'A'  &&  c <= 'Z')
    printf("%d\n", c);
  return 0;
}
