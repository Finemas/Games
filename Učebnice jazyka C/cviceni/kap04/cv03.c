/*
 * cv03.c    v.2.0
 *
 * Formatovane cteni - dekadicky
 * =============================
 *
 */

#include <stdio.h>

int main(void)
{
  int i;

  printf("Zadej dekadicke cislo v rozsahu 0 .. 255: ");
  scanf("%d", &i);
  printf("%2Xh\n", i);
  return 0;
}

