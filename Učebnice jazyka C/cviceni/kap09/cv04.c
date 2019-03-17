/*
 * cv03.c    v.2.0
 *
 * Funkce pro zjisteni cetnosti znaku v souboru
 * ============================================
 *
 */

#include <stdio.h>

/* uplny funkcni prototyp */
int vyskyt(FILE *fr, char c);

int main(void)
{
  FILE *fr;
  char jmeno[100];
  int c;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  /* vyprazdneni bufferu klavesnice */
  while (getchar() != '\n')
    ;

  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor %s nebyl otevren.\n", jmeno);
    return 1;
  }

  printf("Zadej zkoumany znak: ");
  c = getchar();
  printf("Znak '%c' je v souboru %s %d-krat\n", c, jmeno, vyskyt(fr, c));

  if (fclose(fr) == EOF)
    printf("Soubor %s nebyl zavren.\n", jmeno);

  return 0;
}


/*
 * cetnost znaku v souboru
 */

int vyskyt(FILE *fr, char c)
{
  int pocet = 0;
  int ch;

  while ((ch = getc(fr)) != EOF) {
    if (ch == c)
      pocet++;
  }
  return pocet;
}
