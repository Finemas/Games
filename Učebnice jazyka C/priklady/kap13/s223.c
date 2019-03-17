/*
 * s223.c    v.2.0
 *
 * Ukazka funkce pro alokovani dvourozmerneho pole s int prvky
 * ===========================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int yy[2][3], i, j;
  int **xx = (int **) yy;

  for (i = 0;  i < 2;  i++)       /* pro kazdou radku */
    for (j = 0;  j < 3;  j++)     /* pro kazdy sloupec */
      yy[i][j] = i + j;

  for (i = 0;  i < 2;  i++) {
    for (j = 0;  j < 3;  j++)
      printf("%d ", xx[i][j]);
    putchar('\n');
  }
  return 0;
}

