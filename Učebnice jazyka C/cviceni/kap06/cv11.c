/*
 * cv11.c    v.2.0
 *
 * Vraceni precteneho znaku zpet na vstup
 * ======================================
 *
 * Pozor: Pracuje se souborem CISLA11.TXT
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr;
  int c, cislo,
      suma = 0;

  if ((fr = fopen("CISLA11.TXT", "r")) == NULL)  {
    printf("Soubor CISLA11.TXT se nepodarilo otevrit\n");
    return 1;
  }

  while (1) {
    /* cteni uvodnich znaku '$' */
    while ((c = getc(fr)) == '$')
      ;

    if (c == EOF)
      break;

    /* vraceni prvniho znaku cisla zpet do souboru */
    ungetc(c, fr);           
    fscanf(fr, "%d\n", &cislo);
    suma += cislo;
  }

  printf("Soucet cisel je: %d\n", suma);

  if (fclose(fr) == EOF)
    printf("Soubor CISLA11.TXT se nepodarilo uzavrit\n");

  return 0;
}

