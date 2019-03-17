/*
 * s169.c    v.2.0
 *
 * Pointer jako navratova hodnota funkce
 * =====================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

double *init(void)
{
  return ( (double *) malloc(SIZE * sizeof(double)) );
}

void cteni(double *p_f)
{
  int i;

  for (i = 0;  i < SIZE;  i++) {
    printf("Zadejte %d. cislo: ", i + 1);
    scanf("%lf", p_f + i);       /* zde neni & */
  }
}

void nasob(double *p_f, int size, double *p_soucin)
{
  for (size--, *p_soucin = *(p_f + size);  --size >= 0; )
    *p_soucin *= *(p_f + size);
}

int main(void)
{
  double *p_dbl, souc;

  if ((p_dbl = init()) == NULL)
    /* nedostatek pameti - konec */
    return 1;

  cteni(p_dbl);
  nasob(p_dbl, SIZE, &souc);
  printf("Soucin cisel je: %.3f\n", souc);
  return 0;
}

