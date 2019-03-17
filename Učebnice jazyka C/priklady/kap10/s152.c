/*
 * s152.c    v.2.0
 *
 * Volani odkazem
 * ==============
 */

#include <stdio.h>

void vymen(int *p_x, int *p_y)
{
  int pom;

  pom = *p_x;
  *p_x = *p_y;
  *p_y = pom;
}

int main(void)
{
  int i = 5,
      j = 3;

  printf("Pred vymenou: i = %d, j = %d\n", i, j);
  vymen(&i, &j);
  printf("Po vymene   : i = %d, j = %d\n", i, j);
  return 0;
}

