/*
 * cv10.c    v.2.0
 *
 * Vypis poctu znaku na jednotlivych radkach souboru
 * =================================================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  100             /* max. delka retezce */

int main(void)
{
  FILE *fr;
  char jmeno[MAX];
  char radka[MAX];
  int  cislo_radky = 0;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);

  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor '%s' nebyl otevren.\n", jmeno);
    return 1;
  }

  printf("Soubor '%s' ma na jednotlivych radkach znaku:\n", jmeno);

  while (fgets(radka, MAX, fr) != NULL) {
    printf("%3d:%2d  ", ++cislo_radky, strlen(radka) - 1);
  }
  putchar('\n');

  if (fclose(fr) == EOF)
    printf("Soubor '%s' nelze uzavrit.\n", jmeno);

  return 0;
}

