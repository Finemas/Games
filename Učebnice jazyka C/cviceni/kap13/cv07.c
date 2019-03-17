/*
 * cv07.c    v.2.0
 *
 * Dynamicke pole - dolni trojuhelnikova matice
 * ============================================
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX   10

/* uplne funkcni prototypy */
void napln(int **x, int pocet_radek);
void tiskni(int **x, int pocet_radek);

int main(void)
{
  int *p_a[MAX];
  int i;

  /* vytvoreni matice */
  for (i = 0;  i < MAX;  i++) {
    if ((p_a[i] = (int *) malloc((i + 1) * sizeof(int))) == NULL) {
      printf("Malo dynamicke pameti!\n");
      return 1;
    }
  }

  napln((int **)p_a, MAX);
  tiskni((int **)p_a, MAX);

  return 0;
}


/*
 * inicializace matice
 */

void napln(int **x, int pocet_radek)
{
  int i, j;

  for (i = 0;  i < pocet_radek;  i++)
    for (j = 0;  j <= i;  j++)
      x[i][j] = i * pocet_radek + j;
}



/*
 * tisk matice
 */

void tiskni(int **x, int pocet_radek)
{
  int i, j;

  for (i = 0;  i < pocet_radek;  i++) {
    for (j = 0;  j <= i;  j++)
      printf("%2d  ", x[i][j]);
    putchar('\n');
  }
}

