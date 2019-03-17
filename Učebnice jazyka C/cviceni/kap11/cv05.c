/*
 * cv05.c    v.2.0
 *
 * Predani pole a poctu jeho prvku do funkce
 * =========================================
 *
 */

#include <stdio.h>

#define MAX   10

/* uplny funkcni prototyp */
void serad(int x[], int y[], int pocet);
void tiskni(int x[], int y[], int pocet);

int main(void)
{
  int  a[MAX] = { 5, 8, 2, 1, 9, 4, 6, 0, 7, 3 };
  int  b[MAX];
  int  c[2 * MAX], d[2 * MAX];
  int  i;

  serad(a, b, MAX);
  tiskni(a, b, MAX);

  /* nastaveni pole c[] */
  for (i = 0;  i < 2 * MAX;  i++)
    c[i] = 2 * MAX - i;

  serad(c, d, 2 * MAX);
  tiskni(c, d, 2 * MAX);

  return 0;
}


/*
 * serazeni pole podle velikosti vzestupne
 */

void serad(int x[], int y[], int pocet)
{
  int  i, j, min;

  /* prekopirovani pole x[] do pole y[] */
  for (i = 0;  i < pocet;  i++) {
    y[i] = x[i];
  }

  /* serazeni pole y[] metodou vymeny prvku */
  for (i = 0;  i < pocet - 1;  i++) {
    min = y[i];
    for (j = i + 1;  j < pocet;  j++) {
      if (y[j] < min) {
        y[i] = y[j];
        y[j] = min;
        min = y[i];
      }
    }
  }
}

/*
 * vytiskne dve pole
 */

void tiskni(int x[], int y[], int pocet)
{
  int i;

  printf("\n\nNeserazene pole:\n");
  for (i = 0;  i < pocet;  i++)
    printf("%2d ", x[i]);

  printf("\nSerazene pole:\n");
  for (i = 0;  i < pocet;  i++)
    printf("%2d ", y[i]);
}

