/*
 * cv03.c    v.2.0
 *
 * Pole statickych struktur
 * ========================
 *
 */

#include <stdio.h>
#include <string.h>

#define JMENO_SOUBORU   "OSOBY.TXT"

#define DELKA_JM   30           /* delka jmena */
#define MAX        1000         /* pocet lidi */

typedef struct {
   char          jmeno[DELKA_JM];
   unsigned int  stari;
} CLOVEK;

void napln(CLOVEK *p_osoba, char *p_jm, unsigned int vek)
{
  strcpy(p_osoba->jmeno, p_jm);
  p_osoba->stari = vek;
}

int main(void)
{
  CLOVEK lide[MAX];
  FILE *fr;
  unsigned int i,
               pocet = 0,       /* skutecny pocet lidi v souboru */
               vek;             /* pomocny vek pro nacitami */
  double soucet_veku = 0.0,
         prumerny_vek;
  char   jmeno[DELKA_JM];       /* pomocne jmeno pro nacitani */


  if ((fr = fopen(JMENO_SOUBORU, "r")) == NULL) {
    printf("\nSoubor nelze otevrit!\n");
    return 1;
  }

  while (fscanf(fr, "%s %u", jmeno, &vek) == 2) {
    napln(&lide[pocet++], jmeno, vek);
    soucet_veku += vek;
  }

  if (fclose(fr) == EOF)
    printf("\nSoubor nelze zavrit!\n");

  /* vypocet prumerneho veku s presnosti na roky -
       oriznuti desetinne casti */
  prumerny_vek = (int) soucet_veku / pocet;

  /* vypis vsech lidi v prumernem veku */
  printf("Prumerny vek %u lidi je %.0f roku\n", pocet, prumerny_vek);
  printf("v tomto veku jsou nasledujici lide:\n");

  for (i = 0;  i < pocet;  i++) {
    if (prumerny_vek == lide[i].stari)
      printf(" - %s\n", lide[i].jmeno);
  }

  return 0;
}


