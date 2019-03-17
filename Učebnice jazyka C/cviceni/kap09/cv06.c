/*
 * cv06.c    v.2.0
 *
 * Funkce pro vypis souboru na obrazovku se strankovanim
 * =====================================================
 *
 */

#include <stdio.h>

#define RADKY_OBR  20

/* uplny funkcni prototyp */
void vypis(FILE *fr);

int main(void)
{
  FILE *fr;
  char jmeno[100];

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  /* vyprazdneni bufferu klavesnice */
  while (getchar() != '\n')
    ;

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
  int c, pocet = 1;

  while ((c = getc(fr)) != EOF) {
    putchar(c);
    if (c == '\n') {
      if (++pocet >= RADKY_OBR) {
        pocet = 1;
        while (getchar() != '\n')
          ;
      }
    }
  }
}

