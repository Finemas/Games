/*
 * cv06.c    v.2.0
 *
 * Predani pole a poctu jeho prvku do funkce - kopirovani sudych prvku
 * ===================================================================
 *
 */

#include <stdio.h>

#define MAX   10

/* uplny funkcni prototyp */
int sude(int x[], int y[], int pocet);
void tiskni(int x[], int pocet_x, int y[], int pocet_y);

int main(void)
{
  int  a[MAX] = { 5, 8, 2, 1, 9, 4, 6, 0, 7, 3 };
  int  b[MAX];
  int  c[2 * MAX], d[2 * MAX];
  int  i, kolik;

  kolik = sude(a, b, MAX);
  tiskni(a, MAX, b, kolik);

  /* nastaveni pole c[] */
  for (i = 0;  i < 2 * MAX;  i++)
    c[i] = 2 * MAX - i;

  kolik = sude(c, d, 2 * MAX);
  tiskni(c, i, d, kolik);

  return 0;
}


/*
 * kopirovani pouze sudych prvku do pole y[]
 */

int sude(int x[], int y[], int pocet)
{
  int  i,
       kolik = 0;

  for (i = 0;  i < pocet;  i++) {
    if (x[i] % 2 == 0)
      y[kolik++] = x[i];
  }
  return kolik;
}


/*
 * vytiskne dve pole
 */

void tiskni(int x[], int pocet_x, int y[], int pocet_y)
{
  int i;

  printf("\n\nPuvodni pole:\n");
  for (i = 0;  i < pocet_x;  i++)
    printf("%2d ", x[i]);

  printf("\nPole jen se sudymi prvky:\n");
  for (i = 0;  i < pocet_y;  i++)
    printf("%2d ", y[i]);
}

