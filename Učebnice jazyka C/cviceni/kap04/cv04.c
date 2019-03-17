/*
 * cv04.c    v.2.0
 *
 * Formatovane cteni - realne cislo - a vypocet dane
 * =================================================
 *
 */

#include <stdio.h>

int main(void)
{
  double f;

  printf("Zadejte cenu bez dane: ");
  scanf("%lf", &f);
  printf("Prodejni cena s dani (25%%): %.2f\n", f * 1.25);
  return 0;
}

