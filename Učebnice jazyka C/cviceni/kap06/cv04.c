/*
 * cv04.c    v.2.0
 *
 * Zjistovani poctu pismen na radce
 * ================================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr, *fw;
  int c,
      pocet = 0;                /* pocet pismen na radce */

  if ((fr = fopen("PISMENA.TXT", "r")) == NULL) {
    printf("Soubor PISMENA.TXT se nepodarilo otevrit\n");
    return 1;
  }
  if ((fw = fopen("KOLIK.TXT", "w")) == NULL) {
    printf("Soubor KOLIK.TXT se nepodarilo otevrit\n");
    return 1;
  }

  do {
    while ((c = getc(fr)) != EOF  &&  c != '\n') {
      pocet++;
      putc(c, fw);              /* zapis znaku do souboru */
    }
    /* zapis poctu znaku do souboru */
    fprintf(fw, "\n%d\n", pocet);

    pocet = 0;
  } while (c != EOF);

  if (fclose(fr) == EOF)
    printf("Soubor PISMENA.TXT se nepodarilo uzavrit\n");
  if (fclose(fw) == EOF)
    printf("Soubor KOLIK.TXT se nepodarilo uzavrit\n");

  return 0;
}

