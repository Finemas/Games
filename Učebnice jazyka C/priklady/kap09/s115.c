/*
 * s115.c    v.2.0
 *
 * Funkce nevracejici typ int - uplny funkcni prototyp
 * ===================================================
 */

#include <stdio.h>

double pikrat(double x);        /* uplny funkcni prototyp */

int main(void)
{
  double r;

  printf("Zadej polomer: ");
  scanf("%lf", &r);
  printf("Obvod kruhu je %f\n", 2 * pikrat(r));
  return 0;
}

double pikrat(double x)
{
  return (x * 3.14);
}

