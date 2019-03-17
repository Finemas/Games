/*
 * cv02.c    v.2.0
 *
 * Rotace bitu doprava
 * ===================
 *
 */

#include <stdio.h>


/*
 * rotuje bity doprava
 */
unsigned rotuj_doprava(unsigned int x, int n)
{
  unsigned int i, k;

  /* priprava jednicky v nejvyssim bitu */
  k = ~0;                       /* v k same jednicky */
  k >>= 1;                      /* na nejvyssim bitu nula */
  k = ~k;                       /* na nejvyssim bitu jednicka */

  while (n-- != 0) {
    i = x & 1;
    x >>= 1;
    x |= (i == 1)  ?  k  :  0;
  }

  return x;
}


int main(void)
{
  unsigned cislo = 5;
  int i;

  for (i = 0;  i <= sizeof(int) * 8;  i++) {
    printf("Cislo %0*Xh po rotaci doprava o %2d bitu: %0*Xh\n", sizeof(int) * 2,
           cislo, i, sizeof(int) * 2, rotuj_doprava(cislo, i));
  }

  return 0;
}

