/*
 * cv06.c    v.2.0
 *
 * Dvourozmerne pole jako skutecny parametr funkce
 * ===============================================
 *
 */

#include <stdio.h>

#define MAX   10

/* uplne funkcni prototypy */
void napln(int x[][MAX], int pocet_radek);
void tiskni(int x[][MAX], int pocet_radek);

int main(void)
{
  int a[MAX][MAX];

  napln(a, MAX);
  tiskni(a, MAX);

  return 0;
}


/*
 * inicializace matice
 */

void napln(int x[][MAX], int pocet_radek)
{
  int i, j;

  for (i = 0;  i < pocet_radek;  i++)
    for (j = 0;  j < MAX;  j++)
      x[i][j] = i * pocet_radek + j;
}

/*
 * tisk matice
 */
void tiskni(int x[][MAX], int pocet_radek)
{
  int i, j;

  for (i = 0;  i < pocet_radek;  i++) {
    for (j = 0;  j < MAX;  j++)
      printf("%2d  ", x[i][j]);
    putchar('\n');
  }
}

