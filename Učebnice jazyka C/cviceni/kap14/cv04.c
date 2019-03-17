/*
 * cv04.c    v.2.0
 *
 * Pole dynamickych struktur
 * =========================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JMENO_SOUBORU   "OSOBYMOC.TXT"

#define DELKA_JM   30           /* delka jmena */
#define MAX        1000         /* pocet lidi */

typedef struct clovek {
   char          jmeno[DELKA_JM];
   unsigned int  stari;
   struct clovek *p_dalsi;
} CLOVEK;

void napln(CLOVEK *p_osoba, char *p_jm, unsigned int vek)
{
  strcpy(p_osoba->jmeno, p_jm);
  p_osoba->stari = vek;
}

int main(void)
{
  CLOVEK *p_prvni = NULL,
         *p_akt, *p_pom;
  FILE *fr;
  unsigned int pocet = 0,       /* skutecny pocet lidi v souboru */
               vek;             /* pomocny vek pro nacitami */
  double soucet_veku = 0.0,
         prumerny_vek;
  char   jmeno[DELKA_JM];       /* pomocne jmeno pro nacitani */


  if ((fr = fopen(JMENO_SOUBORU, "r")) == NULL) {
    printf("Soubor nelze otevrit!\n");
    return 1;
  }

  while (fscanf(fr, "%s %u", jmeno, &vek) == 2) {
    /* alokovani nove struktury */
    if ((p_pom = (CLOVEK *) malloc(sizeof(CLOVEK))) == NULL) {
      printf("Malo pameti\n");
      /* program se neukonci, ale pracuje jen s temi daty, ktera
         se podarilo ulozit do pameti */
      break;
    }
    pocet++;

    if (p_prvni == NULL)
       p_prvni = p_pom;
    else
       p_akt->p_dalsi = p_pom;  /* pripojeni struktury do retezce */

    p_akt = p_pom;              /* soucasny prvek se stava aktualnim */
    p_akt->p_dalsi = NULL;      /* nulovani ukazatele = konec retezu */
    napln(p_akt, jmeno, vek);
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
  printf("Stiskni <Enter> pro pokracovani ...");
  (void) getchar();

  for (p_akt = p_prvni;  p_akt->p_dalsi != NULL;  p_akt = p_akt->p_dalsi) {
    if (prumerny_vek == p_akt->stari)
      printf(" - %s\n", p_akt->jmeno);
  }

  return 0;
}
 
