/*
 * s42a.c    v.2.0
 *
 * Ruzne moznosti tisku pomoci printf()
 * ====================================
 */

#include <stdio.h>

int main()
{
  int i = 2,
      j = 3;

  printf("Soucet je %d", i + j);

  putchar('\n');
  printf("Pracovali na 100%%");

  putchar('\n');
  printf("Soucet je %d\tSoucin je %d\n", i + j, i * j);

  printf("\007Chyba, pokus o deleni nulou.\n");

  printf("Toto je \"backslash\" : '\\'\n");

  printf("Toto je 'backslash' : '\\'\n");
  return 0;
}
