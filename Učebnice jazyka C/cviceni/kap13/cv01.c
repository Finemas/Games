/*
 * cv01.c    v.2.0
 *
 * Pristup do dvourozmerneho pole pomoci indexu a pointeru
 * =======================================================
 *
 */

#include <stdio.h>

#define MAX   10

int main(void)
{
  int a[MAX][MAX];
  int i, j, *p_a;

  /* inicializace matice */
  for (i = 0;  i < MAX;  i++)
    for (j = 0;  j < MAX;  j++)
      a[i][j] = i * MAX + j;

  /* tisk matice */
  for (i = 0;  i < MAX;  i++) {
    for (p_a = a[i];  p_a < a[i] + MAX;  p_a++)
      printf("%2d  ", *p_a);
    putchar('\n');
  }
  return 0;
}

