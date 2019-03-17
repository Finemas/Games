/*
 * s85a.c    v.2.0
 *
 * Vraceni precteneho znaku na vstup
 * =================================
 */

#include <stdio.h>

int main()
{
  int c, hodnota = 0;

  while ((c = getchar()) >= '0'  &&  c <= '9') {
    hodnota = hodnota * 10 + (c - '0');
  }
  ungetc(c, stdin);

  printf("Nactene cislo = %d\n", hodnota);

  c = getchar();
  printf("Ukoncujici znak = %c\n", c);
  return 0;
}

