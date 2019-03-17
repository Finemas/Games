/*
 * cv02.c    v.2.0
 *
 * Cteni ze souboru a zapis do souboru
 * ===================================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr, *fw;
  int c;

  if ((fr = fopen("PISMENA.TXT", "r")) == NULL) {
    printf("Soubor PISMENA.TXT se nepodarilo otevrit\n");
    return 1;
  }
  if ((fw = fopen("VELKY.TXT", "w")) == NULL) {
    printf("Soubor VELKY.TXT se nepodarilo otevrit\n");
    return 1;
  }

  while ((c = getc(fr)) != EOF) {
    putchar(c);                 /* vypis na obrazovku */

    /* prevedeni na velka pismena */
    c = (c >= 'a'  &&  c <= 'z') ? c - ('a' - 'A') : c;
    putc(c, fw);                /* zapis do souboru */
  }

  if (fclose(fr) == EOF)
    printf("Soubor PISMENA.TXT se nepodarilo uzavrit\n");
  if (fclose(fw) == EOF)
    printf("Soubor VELKY.TXT se nepodarilo uzavrit\n");

  return 0;
}
