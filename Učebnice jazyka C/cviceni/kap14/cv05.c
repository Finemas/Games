/*
 * cv05.c    v.2.0
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
  char radka[MAX_DELKA_RADKY];
  int  delka;                   /* aktualni delka radky */
  struct radka *p_dalsi;
} RADKA;

/*
 * nacte jednu radku ze souboru a zkopiruje ji do prvku struktury
 * v pripade konce souboru vraci KONEC_SOUBORU
 * v pripade uspechu OK
 */
VYSLEDEK_CTENI nacti_a_uloz_radku(FILE *fr, RADKA *p_prvek)
{
  if (fgets(p_prvek->radka, MAX_DELKA_RADKY - 1, fr) != NULL) {
    /* ulozeni delky radky */
    p_prvek->delka = strlen(p_prvek->radka);
    return (OK);
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

  while ((vysledek = nacti_a_uloz_radku(fr, p_akt)) == OK) {
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
        *p_akt,
        *p_max;                 /* ukazatel na prvek s nejdelsi radkou */
  int   max_delka;

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

  /* nalezeni max. delky radky */
  p_akt = p_prvni;
  max_delka = p_prvni->delka;
  p_max = p_prvni;

  while (p_akt->p_dalsi != NULL) {
    if (p_akt->delka > max_delka) {
      max_delka = p_akt->delka;
      p_max = p_akt;
    }
    p_akt = p_akt->p_dalsi;
  }

  printf("Maximalni delka radky je: %d\n", max_delka);

  printf("Je to tato radka:\n%s", p_max->radka);

  return 0;
}

