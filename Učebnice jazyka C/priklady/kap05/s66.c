/*
 * s66.c    v.2.0
 *
 * Ukazka pouziti prikazu return
 * =============================
 */

#include <stdio.h>

int x[10], a[10], b[10];      /* definice globalnich poli */

int nasobeni()
{
  int i, j, k;

  for (i = 0;  i < 10;  i++) {
    for (j = 0;  j < 10;  j++) {
      for (k = 0;  k < 10;  k++) {
        if (x[k] == 0)
          return 0;              /* neuspech */
        a[i] = a[i] + b[j] / x[k];
      }
    }
  }
  return 1;                      /* uspech */
}


int main()
{
  int i, vysledek;

  /* inicializace poli */
  for (i = 0;  i < 10;  i++) {
    x[i] = i + 1;
    a[i] = (i + 1) * 2;
    b[i] = (i + 1) * (i + 1);
  }

  x[5] = 0;                     /* nulovy delitel */

  vysledek = nasobeni();
  if (vysledek == 0)
    printf("Nulovy delitel\n");
  else {
    /* tisk pole */
    for (i = 0;  i < 10;  i++)
      printf("%d ", a[i]);
  }
  return 0;
}
