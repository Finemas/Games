/*
 * cv09.c    v.2.0
 *
 * Konverze znaku - mala na VELKA
 * ==============================
 *
 */

#include <stdio.h>

int main(void)
{
  int c1, c2, c3;

  printf("Zadejte 3 mala pismena: ");
  c1 = getchar() - ('a' - 'A');
  c2 = getchar() - ('a' - 'A');
  c3 = getchar() - ('a' - 'A');

  printf("Velka pismena v obracenem poradi: %c%c%c\n", c3, c2, c1);
  return 0;
}

