/*
 * cv02.c    v.2.0
 *
 * Vyuziti ternarniho operatoru
 * ============================
 *
 */

#include <stdio.h>

int main(void)
{
  int i, j;

  printf("Zadej dve cela cisla: ");
  scanf("%d %d", &i, &j);

  printf("Mensi cislo: %d\n", (i < j) ? i : j);
  printf("Vetsi cislo: %d\n", (i > j) ? i : j);
  return 0;
}

