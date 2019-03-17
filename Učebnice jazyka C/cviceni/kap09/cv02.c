/*
 * cv02.c    v.2.0
 *
 * Funkce pro vypis trojuhelnika
 * =============================
 *
 */

#include <stdio.h>

/* uplny funkcni prototyp */
void troj(char c, int n);

int main(void)
{
  int radky;

  printf("Zadej pocet radek trojuhelnika: ");
  scanf("%d", &radky);
  troj('*', radky);
  return 0;
}


/*
 * vypis trojuhelnika
 */

void troj(char c, int n)
{
  int i, j;

  putchar('\n');

  for (i = 1;  i <= n;  i++) {
    /* tisk uvodnich mezer */
    for (j = 1;  j <= n - i;  j++)
      putchar(' ');
    /* tisk znaku */
    for (j = 1;  j <= i * 2 - 1;  j++)
      putchar(c);
    putchar('\n');
  }
}

