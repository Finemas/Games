/*
 * cv06.c    v.2.0
 *
 * Ulozeni souboru do pameti pomoci spojoveho seznamu
 * ==================================================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DELKA_RADKY   80    /* max. delka radky v souboru */

typedef enum {
  MALO_PAMETI, KONEC_SOUBORU, OK
} VYSLEDEK_CTENI;

typedef struct radka {
  char *p_radka;
  int  delka;                   /* aktualni delka radky */
  struct radka *p_dalsi;
} RADKA;

/*
 * nacte jednu radku ze souboru, alokuje pamet a radku do ni zkopiruje
 * v pripade nedostatku pameti vraci MALO_PAMETI
 * v pripade konce souboru vraci KONEC_SOUBORU
 * v pripade uspechu OK
 */
VYSLEDEK_CTENI nacti_a_uloz_radku(FILE *fr, char **p_line)
{
  char pom_radka[MAX_DELKA_RADKY];

  if (fgets(pom_radka, MAX_DELKA_RADKY - 1, fr) != NULL) {
    /* alokovani pameti pro ulozeni nactene radky + '\0' */
    if ((*p_line = (char *) malloc(strlen(pom_radka) + 1)) != NULL) {
      strcpy(*p_line, pom_radka);
      return (OK);
    }
    else
      return (MALO_PAMETI);
  }
  return (KONEC_SOUBORU);
}

/*
 * nacte soubor po radcich do pameti do spojoveho seznamu
 * v pripade nedostatku pameti vraci MALO_PAMETI
 * jinak vraci KONEC_SOUBORU
 */
VYSLEDEK_CTENI nacti_soubor(FILE *fr, RADKA **p_p_prvni)
{
  VYSLEDEK_CTENI vysledek;
  RADKA *p_akt;

  if ((*p_p_prvni = (RADKA *) malloc(sizeof(RADKA))) == NULL)
    return (MALO_PAMETI);

  p_akt = *p_p_prvni;

  while ((vysledek = nacti_a_uloz_radku(fr, &(p_akt->p_radka))) == OK) {
    /* ulozeni delky radky */
    p_akt->delka = strlen(p_akt->p_radka);

    /* alokovani pameti pro dalsi strukturu */
    if ((p_akt->p_dalsi = (RADKA *) malloc(sizeof(RADKA))) == NULL) {
      vysledek = MALO_PAMETI;
      break;
    }
    else {
      /* posunuti ve spojovem seznamu */
      p_akt = p_akt->p_dalsi;
    }
  }

  /* posledni prvek v seznamu je NULL */
  p_akt->p_dalsi = NULL;

  /* cyklus while se ukonci bud prectenim celeho souboru
     nebo nedostatkem pameti */
  return vysledek;
}

int main(void)
{
  FILE  *fr;
  char  jmeno_souboru[100];
  RADKA *p_prvni = NULL,
        *p_akt, *p_tmp;
  int   i;
  unsigned long int prum_delka;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno_souboru);

  if ((fr = fopen(jmeno_souboru, "r")) == NULL) {
    printf("Soubor %s nelze otevrit\n", jmeno_souboru);
    return 1;
  }

  /* nacteni souboru do pameti */
  if (nacti_soubor(fr, &p_prvni) == MALO_PAMETI) {
    printf("Soubor '%s' se nepodarilo nacist cely do pameti.\n",
           jmeno_souboru);
    (void) getchar();
  }

  if (fclose(fr) == EOF) {
    printf("Soubor %s nelze uzavrit\n", jmeno_souboru);
  }

  /* vypocet prumerne delky radky */
  p_akt = p_prvni;
  i = 0;
  prum_delka = 0;

  while (p_akt->p_dalsi != NULL) {
    i++;
    /* delka se pocita bez ukoncujiciho znaku '\n' */
    prum_delka += p_akt->delka - 1;
    p_akt = p_akt->p_dalsi;
  }
  prum_delka /= i;
  printf("Prumerna delka radky je: %lu\n", prum_delka);

  printf("Tuto delku maji nasledujici radky\n");

  /* tisk vsech radek prumerne delky */
  p_akt = p_prvni;

  while (p_akt->p_dalsi != NULL) {
    if (prum_delka == strlen(p_akt->p_radka) - 1)
      printf("%s", p_akt->p_radka);
    p_akt = p_akt->p_dalsi;
  }

  /* zaverecne uvolneni pameti */
  p_akt = p_prvni;

  while (p_akt->p_dalsi != NULL) {
    free((void *) p_akt->p_radka);       /* uvolneni retezce */
    p_tmp = p_akt;
    p_akt = p_akt->p_dalsi;
    free((void *) p_tmp);                /* uvolneni uzlu */
  }

  return 0;
}

