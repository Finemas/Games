/*
 * cv08.c    v.2.0
 *
 * Vypis souboru na obrazovku
 * ==========================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  100             /* max. delka retezce */

int main(void)
{
  FILE *fr;
  char jmeno[MAX];
  char pripona[4];
  char radka[MAX];

  printf("Zadej pouze jmeno souboru (bez pripony): ");
  scanf("%s", radka);
  printf("Zadej priponu souboru (bez tecky) [0-3 znaky]: ");
  scanf("%3s", pripona);

  /* slozeni uplneho jmena souboru */
  sprintf(jmeno, "%s.%s", radka, pripona);

  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor '%s' nebyl otevren.\n", jmeno);
    return 1;
  }

  while (fgets(radka, MAX, fr) != NULL)
    printf("%s", radka);

  if (fclose(fr) == EOF)
    printf("Soubor '%s' nelze uzavrit.\n", jmeno);

  return 0;
}

