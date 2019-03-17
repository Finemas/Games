/*
 * cv04.c    v.2.0
 *
 * Pocet pismen na kazde radce souboru
 * ===================================
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX   ('Z' - 'A' + 1)
#define STOP  20

/* uplny funkcni prototyp */
void zjisteni_poctu_na_radce(FILE *fr, int pocty[]);
void vypis_poctu(int pocty[]);

int main(void)
{
  FILE *fr;
  int  pocty[MAX];
  char jmeno[100];
  int  i;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor %s nebyl otevren.\n", jmeno);
    return 1;
  }

  printf("Pocty jednotlivych pismen na jednotlivych radkach souboru '%s'\n",
          jmeno);

  printf("===========================================================");
  /* podtrzeni nadpisu v presne delce jmena souboru */
  for (i = 1;  i <= strlen(jmeno) + 1;  i++)
    putchar('=');

  printf("\n  ");
  for (i = 0;  i < MAX;  i++)
    printf(" %2c", i + 'A');

  for (i = 1;  i <= STOP;  i++) {
    printf("%2d", i);
    zjisteni_poctu_na_radce(fr, pocty);
    vypis_poctu(pocty);
  }

  if (fclose(fr) == EOF)
    printf("Soubor %s nebyl zavren.\n", jmeno);

  return 0;
}


/*
 * zjisteni poctu pismen na jedne radce souboru
 */

void zjisteni_poctu_na_radce(FILE *fr, int pocty[])
{
  int c, i;

  /* nulovani pole pocty[] */
  for (i = 0;  i < MAX;  i++) {
    pocty[i] = 0;
  }

  while ((c = getc(fr)) != '\n') {
    if (isalpha(c) != 0) {
      /* je to pismeno */
      i = toupper(c) - 'A';     /* prevedeni na velka pismena a index */
      pocty[i]++;
    }
  }
}


/*
 * vypise pocet pismen na radce
 */

void vypis_poctu(int pocty[])
{
  int i;

  for (i = 0;  i < MAX;  i++) {
    if (pocty[i] == 0)
      printf("   ");
    else
      printf(" %2d", pocty[i]);
  }
}

