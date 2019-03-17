/*
 * cv01.c    v.2.0
 *
 * Funkce pro tabulaci prirozenych mocnin
 * ======================================
 *
 */

#include <stdio.h>

/* uplny funkcni prototyp */
void tabulka_mocnin(double x, int n);

int main(void)
{
  double zaklad;
  int    mocnina;

  printf("Zadej cislo, ktere se bude umocnovat: ");
  scanf("%lf", &zaklad);
  printf("Zadej nejvyssi mocninu: ");
  scanf("%d", &mocnina);
  tabulka_mocnin(zaklad, mocnina);
  return 0;
}

/*
 * tabulace mocnin daneho zakladu
 */

void tabulka_mocnin(double x, int n)
{
  int i;
  double pom = 1.0;

  printf("\nTabulka mocnin cisla %f\n", x);
  printf("=====================================\n");

  for (i = 1;  i <= n;  i++) {
    pom *= x;
    printf("%d \t %15.5f\n", i, pom);
  }
}

