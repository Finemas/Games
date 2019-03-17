/*
 * cv06.c    v.2.0
 *
 * Komplikovane formatove cteni cisel ze souboru
 * =============================================
 *
 * Pokud nebude program fungovat, vyzkousejte jiny format pro cteni !!!
 *
 */

#include <stdio.h>

int main(void)
{
  FILE   *fr;
  double cislo,
         suma;
  int    pocet;                 /* pocet prectenych cislic */

  pocet = 0;
  suma = 0;
  if ((fr = fopen("CISLA.TXT", "r")) == NULL)  {
    printf("Soubor CISLA.TXT se nepodarilo otevrit\n");
    return 1;
  }

  /* nastaveni formatu cteni provedte jen zde na:
       1) "$%lf"
       2) "$%lf\n"
       3) " $%lf"
       4) " $%lf\n"
  */
  while (fscanf(fr, " $%lf\n", &cislo) == 1) {
    pocet++;
    suma += cislo;
  }

  printf("Aritmeticky prumer je: %f\n", suma / pocet);

  if (fclose(fr) == EOF)
    printf("Soubor CISLA.TXT se nepodarilo uzavrit\n");

  return 0;
}

