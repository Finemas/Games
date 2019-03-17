/*
 * s54.c    v.2.0
 *
 * Prikaz if-else
 * ==============
 */

#include <stdio.h>

int main()
{
  double x, y, z, max;

  printf("Zadej tri realna cisla: ");
  scanf("%lf %lf %lf", &x, &y, &z);
                     /* prazdna radka zvysuje prehlednost */
  if (x > y) {       /* zavorka { neni nutna, ale vhodna */
    if (x > z)
      max = x;
    else
      max = z;
  }                  /* zavorka } neni nutna, ale vhodna */
  else {             /* zavorka { neni nutna, ale vhodna */
    if (y < z)
      max = z;
    else
      max = y;
  }                  /* zavorka } neni nutna, ale vhodna */
                     /* prazdna radka zvysuje prehlednost */
  printf("\nNejvetsi cislo je %f\n", max);
  return 0;
}
