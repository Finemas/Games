/*
 * cv05.c    v.2.0
 *
 * Funkce pro vypis souboru na obrazovku
 * =====================================
 *
 */

#include <stdio.h>

/* uplny funkcni prototyp */
void vypis(FILE *fr);

int main(void)
{
  FILE *fr;
  char jmeno[100];
  int c;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor %s nebyl otevren.\n", jmeno);
    return 1;
  }

  vypis(fr);

  if (fclose(fr) == EOF)
    printf("Soubor %s nebyl zavren.\n", jmeno);

  return 0;
}

/*
 * vypis souboru
 */

void vypis(FILE *fr)
{
  int c;

  while ((c = getc(fr)) != EOF)
    putchar(c);
}

