/*
 * s239.c    v.2.0
 *
 * Ukazka struktury ve strukture
 * =============================
 */

#include <stdio.h>
#include <string.h>

#define MAX   1000

typedef struct {
  char ulice[30];
  int  cislo;
} ADRESA;

typedef struct {
  char   jmeno[20];
  ADRESA adresa;
  float  plat;
} OSOBA;

OSOBA lide[MAX];

int main(void)
{
  int j;

  for (j = 0;  j < MAX;  j++) {
    sprintf(lide[j].jmeno, "%d. clovek", j);
    sprintf(lide[j].adresa.ulice, "%d. avenue", j);
    lide[j].adresa.cislo = j + 1;
    lide[j].plat = j + 100;
  }

  {  /* blok */
    int   i, kdo = 0;
    float max = 0,
          pom;
    for (i = 0;  i < MAX;  i++) {
      if ((pom = lide[i].plat) > max) {
        max = pom;
        kdo = i;
      }
    }
    printf("Zamestnanec s nejvetsim platem bydli v: %s %d\n",
            lide[kdo].adresa.ulice, lide[kdo].adresa.cislo);

  }


  {  /* blok */
    float max = lide[0].plat;
    OSOBA *p_pom, *p_kdo;

    for (p_pom = p_kdo = lide; p_pom < lide + MAX;  p_pom++) {
      if ((p_pom->plat) > max) {
        p_kdo = p_pom;
        max = p_pom->plat;
      }
    }
    printf("Zamestnanec s nejvetsim platem bydli v: %s %d\n",
            p_kdo->adresa.ulice, p_kdo->adresa.cislo);
  }
  return 0;
}

