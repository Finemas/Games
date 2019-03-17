/*
 * cv08.c    v.2.0
 *
 * Vypis libovolneho souboru
 * =========================
 *
 */

#include <stdio.h>
#include <ctype.h>

#define RADKY_OBR  20

/* uplny funkcni prototyp */
void vypis(FILE *fr);
double vypis_soubor(void);

int main(void)
{
   while (vypis_soubor() != 2.2)
     ;
  return 0;
}

double vypis_soubor(void)
{
  FILE *fr;
  char jmeno[100];

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  /* vycisteni klavesnicoveho bufferu */
  while (getchar() != '\n')
     ;

  if (toupper(jmeno[0]) == 'K')
    return 2.2;

  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor %s nebyl otevren.\n", jmeno);
    return 1.1;
  }

  vypis(fr);

  if (fclose(fr) == EOF)
    printf("Soubor %s nebyl zavren.\n", jmeno);

  return 0.5;
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

