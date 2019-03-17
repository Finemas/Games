/*
 * cv12.c    v.2.0
 *
 * Ruzne vyznamy operatoru /
 * =========================
 *
 */

#include <stdio.h>

int main(void)
{
  int i, j;
  double f, g;

  printf("Celociselne a realne deleni\n");
  printf("Delenec   Delitel    Cele   Realne\n");
  i = 7; j = 2;
  f = 7.0; g = 2.0;
  printf("%5d   / %5d   = %5d  %5.2f\n", i, j, (int)(i/j), (double)(i/j));
  printf("%5.2f   / %5d   = %5d  %5.2f\n", f, j, (int)(f/j), (double)(f/j));
  printf("%5d   / %5.2f   = %5d  %5.2f\n", i, g, (int)(i/g), (double)(i/g));
  printf("%5.2f   / %5.2f   = %5d  %5.2f\n", f, g, (int)(f/g), (double)(f/g));

  printf("\nDeleni modulo:\n");
  printf("Delenec Delitel  Zbytek\n");
  printf("%4d   %% %3d    = %5d\n", i, j, i % j);
  printf("%4d   %% %3d    = %5d\n", j, i, j % i);
  return 0;
}

