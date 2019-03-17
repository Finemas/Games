/*
 * cv15.c    v.2.0
 *
 * Vypis sudych cisel pomoci cyklu for
 * ===================================
 *
 */

#include <stdio.h>

int main(void)
{
  double f, g;
  int i,
      d,                        /* dolni mez */
      h;                        /* horni mez */

  printf("Zadej dve realna kladna cisla: ");
  scanf("%lf %lf", &f, &g);

  /* nalezeni horni a dolni meze */
  d = (f < g) ? f : g;
  h = (f >= g) ? f : g;

  /* zaokrouhleni na nejblizsi vyssi cele sude cislo */
  d += (d % 2) ? 1 : 0;

  for (i = d;  i <= h;  i += 2)
    printf("%4d  ", i);

  printf("\n");
  return 0;
}

