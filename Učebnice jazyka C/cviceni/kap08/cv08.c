/*
 * cv08.c    v.2.0
 *
 * Presmerovani vstupu s vyuzitim maker
 * ====================================
 *
 */

#include <stdio.h>
#include <ctype.h>

#define POCET           10      /* pocet ctenych cisel */
#define JMENO_SOUBORU   "CISLA.TXT"

int main(void)
{
  FILE *fr;
  int i, c, cislo,
      pocet_sudych = 0;

  printf("Cteni ze Souboru nebo z Klavesnice [S/K]: ");
  while (1) {
    c = toupper(getchar());
    if (c == 'S' ||  c == 'K')
      break;
    else
      putchar('\007');
  }

  if (c == 'S') {
    if ((fr = fopen(JMENO_SOUBORU, "r")) == NULL) {
      printf("Soubor %s nelze otevrit\n", JMENO_SOUBORU);
      return;
    }
  }
  else
    fr = stdin;

  for (i = 1;  i <= POCET;  i++) {
    printf("Zadej %d. cislo: ", i);
    fscanf(fr, "%d", &cislo);
    if (cislo % 2 == 0)
      pocet_sudych++;           /* sude cislo */
  }

  printf("Precetlo se %d sudych cisel\n", pocet_sudych);

  if (fr != stdin)
    fclose(fr);

  return 0;
}

