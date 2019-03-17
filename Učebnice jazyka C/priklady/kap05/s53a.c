/*
 * s53a.c    v.2.0
 *
 * Prikaz if s vyuzitim prirazeni
 * ==============================
 */

#include <stdio.h>

int main()
{
  int c;

  if ((c = getchar()) >= 'A'  &&  c <= 'Z')
    printf("%d\n", c);
  return 0;
}
