/*
 * s74b.c    v.2.0
 *
 * Cteni cisel ze souboru s osetrenim vstupu
 * =========================================
 */

#include <stdio.h>

int main()
{
  FILE *fr;
  double x, y, z;

  fr = fopen("DATA.TXT", "r");

  if (fscanf(fr, "%lf %lf %lf", &x, &y, &z) == 3)
    printf("%f\n", x + y + z);
  else
    printf("Soubor DATA.TXT neobsahuje 3 realna cisla\n");

  fclose(fr);
  return 0;
}

