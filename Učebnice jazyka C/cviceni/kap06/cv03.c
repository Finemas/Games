/*
 * cv03.c    v.2.0
 *
 * Pocet znaku v souboru
 * =====================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr;
  int c;
  long int pocet = 0;               /* pocet znaku v souboru */

  if ((fr = fopen("PISMENA.TXT", "r")) == NULL) {
    printf("Soubor PISMENA.TXT se nepodarilo otevrit\n");
    return 1;
  }

  while ((c = getc(fr)) != EOF)
    pocet++;

  printf("V souboru PISMENA.TXT je %ld znaku\n", pocet);

  if (fclose(fr) == EOF)
    printf("Soubor PISMENA.TXT se nepodarilo uzavrit\n");

  return 0;
}

