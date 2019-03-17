/*
 * cv17.c    v.2.0
 *
 * Definice uvnitr bloku
 * =====================
 *
 */

#include <stdio.h>

int main(void)
{
  int c;

  printf("Zadej typ cisla [d - cele, f - realne]: ");
  c = getchar();

  if (c == 'd') {
    int i;                      /* i je definovano uvnitr bloku */

    printf("Zadej cele cislo: ");
    scanf("%d", &i);
    printf("Nacetli jsme cislo: %d\n", i);
  }
  else {
    float f;                   /* f je definovano uvnitr bloku */

    printf("Zadej realne cislo: ");
    scanf("%f", &f);
    printf("Nacetli jsme cislo: %f\n", f);
  }

  return 0;
}

