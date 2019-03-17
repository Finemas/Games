/*
 * cv12.c    v.2.0
 *
 * Formatovane cteni z klavesnice pomoci for
 * =========================================
 *
 */

#include <stdio.h>

int main(void)
{
  int n,                        /* pocet cisel celkem */
      v_interv = 0,             /* pocet cisel v intervalu */
      i, j;

  printf("Zadej pocet cisel: ");
  scanf("%d", &n);

  for (i = 1;  i <= n;  i++) {
    printf("Zadej %d. cislo: ", i);
    scanf("%d", &j);
    if (j >= 25  &&  j <= 38)
      v_interv++;
  }
  printf("\nBylo precteno %d cisel v intervalu <25, 38>\n", v_interv);
  return 0;
}

