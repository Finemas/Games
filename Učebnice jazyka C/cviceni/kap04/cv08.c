/*
 * cv08.c    v.2.0
 *
 * Konverze znaku - VELKA na mala
 * ==============================
 *
 */

#include <stdio.h>

int main(void)
{
  int c1, c2, c3;

  printf("Zadejte 3 velka pismena: ");
  c1 = getchar() + 'a' - 'A';
  c2 = getchar() + 'a' - 'A';
  c3 = getchar() + 'a' - 'A';

  printf("Mala pismena: %c%c%c\n", c1, c2, c3);
  return 0;
}

