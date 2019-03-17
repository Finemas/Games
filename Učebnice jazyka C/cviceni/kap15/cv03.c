/*
 * cv03.c    v.2.0
 *
 * Inverze skupiny bitu
 * ====================
 *
 */

#include <stdio.h>


/*
 * invertuje skupinu bitu
 */
unsigned invert(unsigned int x, int p, int n)
{
  unsigned int k;

  k = ~0;                       /* v k same jednicky */

  /* kde byly v 'x' jednicky, tam  budou v 'k' nuly,
     kde byly v 'x' nuly, tam budou v 'k' jednicky */
  k ^= x;

  /* oriznuti praveho okraje */
  k = (k >> p) << p;
  /* oriznuti leveho okraje */
  k = (k << (sizeof(int) * 8 - (p + n))) >> (sizeof(int) * 8 - (p + n));

  return k;
}


int main(void)
{
  unsigned cislo = 0;
  int i, j;

  printf("\nCislo %0*Xh po inverzi:\n\n", sizeof(int) * 2, cislo);
  printf("Od bitu  Pocet invertovanych bitu\n");
  printf("cislo |");
  for (j = 0;  j <= 6;  j++)
    printf(" %*d", sizeof(int) * 2, j);
  putchar('\n');

  for (j = 1;  j <= 78;  j++)
    putchar('=');
  putchar('\n');

  for (i = 0;  i <= 6;  i++) {
    printf("%2d.   |", i);
    for (j = 1;  j <= 7 - i;  j++) {
      printf(" %0*X", sizeof(int) * 2, invert(0, i, j));
    }
    putchar('\n');
  }

  return 0;
}

