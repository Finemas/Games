/*
 * s185.c    v.2.0
 *
 * Pointer jako skutecny parametr procedury
 * ========================================
 */

#include <stdio.h>

#define POCET  10

void maxim(double pole[], int pocet, double *p_max)
{
  double *p_pom;

  *p_max = pole[0];
  for (p_pom = pole + 1;  p_pom < pole + pocet;  p_pom++) {
    if (*p_pom > *p_max)
      *p_max = *p_pom;     /* zmena hodnoty na adrese p_max */
  }
}

int main(void)
{
  double f[POCET], max;
  int i;

  for (i = 0;  i < POCET;  i++) {
    printf("Zadej %d. cislo: ", i + 1);
    scanf("%lf", &f[i]);
  }
  maxim(f, POCET, &max);
  printf("Maximum z %d cislic je %f\n", POCET, max);
  return 0;
}

