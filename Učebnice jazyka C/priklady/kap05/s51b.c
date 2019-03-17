/*
 * s51b.c    v.2.0
 *
 * Pouziti operatoru carky
 * =======================
 */

#include <stdio.h>

int main()
{
  int i = 2, j = 4;             /* toto neni operator carky */

  j = (i++, i - j);             /* i bude 3 a j bude -1 */
  printf("i = %d  j = %d\n", i, j);
  return 0;
}
