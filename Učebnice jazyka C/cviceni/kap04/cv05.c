/*
 * cv05.c    v.2.0
 *
 * Vypocet obsahu obdelnika
 * ========================
 *
 */

#include <stdio.h>

int main(void)
{
  double x, y;

  printf("Zadejte delku a sirku: ");
  scanf("%lf %lf", &x, &y);
  printf("Obdelnik o delce %f a sirce %f ma obsah %f\n", x, y, x * y);
  return 0;
}

