/*
 * cv08.c    v.2.0
 *
 * Pokus o otevreni neexistujiciho souboru
 * =======================================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr;

  if ((fr = fopen("NENI.TU", "r")) == NULL) 
    printf("Soubor NENI.TU se nepodarilo otevrit\n");
  else {
    printf("Soubor NENI.TU je otevren\n");
    if (fclose(fr) == EOF)
      printf("Soubor NENI.TU se nepodarilo uzavrit\n");
  }

  return 0;
}

