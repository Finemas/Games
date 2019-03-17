/*
 * cv07.c    v.2.0
 *
 * Pouziti vhnizdene struktury
 * ===========================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DELKA_RADKY   80    /* max. delka radky v souboru */
#define MAX_RADEK       1000    /* max. pocet radek v souboru */

typedef struct {
  int pismena;
  int ostatni;
} ZNAKY;

typedef struct {
  ZNAKY pocet;
  int   delka;                  /* aktualni delka radky */
} RADKA;

/*
 * nacte soubor po radcich a zpracuje ho do pole struktur
 */
int nacti_soubor(FILE *fr, RADKA pole[])
{
  int i,
      pocet_radek = 0,
      pocet_pismen,
      pocet_ostatnich;
  char pom_radka[MAX_DELKA_RADKY];

  while (fgets(pom_radka, MAX_DELKA_RADKY - 1, fr) != NULL) {
    /* ulozeni delky radky */
    pole[pocet_radek].delka = strlen(pom_radka);

    /* zjistovani poctu jednotlivych znaku */
    pocet_pismen = 0;
    pocet_ostatnich = 0;
    for (i = 0;  i < pole[pocet_radek].delka;  i++)
      isalpha(pom_radka[i])  ?  pocet_pismen++  :  pocet_ostatnich++;

    /* ulozeni poctu jednotlivych znaku */
    pole[pocet_radek].pocet.pismena = pocet_pismen;
    pole[pocet_radek].pocet.ostatni = pocet_ostatnich;

    pocet_radek++;
  }
  return pocet_radek;
}


int main(void)
{
  FILE  *fr;
  char  jmeno_souboru[100];
  RADKA radky[MAX_RADEK];
  int   i, pocet_radek;
  unsigned long int  pocet_pismen,
                     pocet_znaku;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno_souboru);

  if ((fr = fopen(jmeno_souboru, "r")) == NULL) {
    printf("Soubor %s nelze otevrit\n", jmeno_souboru);
    return 1;
  }

  /* nacteni a zpracovani souboru */
  pocet_radek = nacti_soubor(fr, radky);

  if (fclose(fr) == EOF) {
    printf("Soubor %s nelze uzavrit\n", jmeno_souboru);
  }

  /* zjisteni poctu pismen v souboru */
  pocet_pismen = 0;
  pocet_znaku = 0;
  for (i = 0;  i < pocet_radek;  i++) {
    pocet_pismen += radky[i].pocet.pismena;
    pocet_znaku += radky[i].delka;
  }

  printf("V souboru '%s' je celkove %lu znaku a z toho %lu pismen\n",
         jmeno_souboru, pocet_znaku, pocet_pismen);

  return 0;
}

