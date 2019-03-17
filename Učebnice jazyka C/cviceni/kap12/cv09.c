/*
 * cv09.c    v.2.0
 *
 * Vypis pouze radek souboru se zadanym slovem
 * ===========================================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  100             /* max. delka retezce */

int main(void)
{
  FILE *fr;
  char jmeno[MAX];
  char slovo[MAX];
  char radka[MAX];

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  printf("Zadej hledane slovo: ");
  scanf("%s", slovo);

  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor '%s' nebyl otevren.\n", jmeno);
    return 1;
  }

  while (fgets(radka, MAX, fr) != NULL) {
    if (strstr(radka, slovo) != NULL)
      printf("%s", radka);
  }

  if (fclose(fr) == EOF)
    printf("Soubor '%s' nelze uzavrit.\n", jmeno);

  return 0;
}

