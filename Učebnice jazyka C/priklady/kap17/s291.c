/*
 * s291.c    v.2.0
 *
 * Kopirovani souboru po radcich
 * =============================
 */

#include <stdio.h>

#define DELKA_RADKY  5

int main(void)
{
  char radka[DELKA_RADKY];
  FILE *fr, *fw;

  fr = fopen("A.TXT", "r");
  fw = fopen("B.TXT", "w");

  while (fgets(radka, DELKA_RADKY, fr) != NULL)
    fputs(radka, fw);

  fclose(fr);
  fclose(fw);
  return 0;
}

