/*
 * s50c    v.2.0
 *
 * Ternarni operator - mene caste pouziti
 * ======================================
 */

#include <stdio.h>

int main()
{
  int i = 1,
      j = 2;

  (i == 1)  ?  i++  :  j++;
  printf("i = %d  j = %d\n", i, j);
  return 0;
}
