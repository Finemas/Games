/*
 * s243.c    v.2.0
 *
 * Struktura ve strukture - dynamicka pamet 4.
 * ===========================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *p_ulice;
  int  cislo;
} ADRESA;

typedef struct {
  char   *p_jmeno;
  ADRESA *p_adresa;
  float  plat;
} OSOBA;

OSOBA lide[2];

int main(void)
{
  char *ulice[] = { "Dlouha", "Kratka" };
  OSOBA *p_o;

  lide[0].plat = 20000.0;
  lide[0].p_jmeno = (char *) malloc(strlen("Karel") + 1);
  strcpy(lide[0].p_jmeno, "Karel");
  lide[0].p_adresa = (ADRESA *) malloc(sizeof(ADRESA));
  lide[0].p_adresa->cislo = 10;
  lide[0].p_adresa->p_ulice = (char *) malloc(strlen(ulice[0]) + 1);
  strcpy(lide[0].p_adresa->p_ulice, ulice[0]);

  lide[1].plat = 21000.0;
  lide[1].p_jmeno = (char *) malloc(strlen("Venca") + 1);
  strcpy(lide[1].p_jmeno, "Venca");
  lide[1].p_adresa = (ADRESA *) malloc(sizeof(ADRESA));
  lide[1].p_adresa->cislo = 20;
  lide[1].p_adresa->p_ulice = ulice[1];

  printf("clovek 1: %s, %s %d, %.0f\n", lide[0].p_jmeno,
          lide[0].p_adresa->p_ulice, lide[0].p_adresa->cislo,
          lide[0].plat);

  p_o = &lide[1];
  printf("clovek 2: %s, %s %d, %.0f\n", p_o->p_jmeno,
          p_o->p_adresa->p_ulice, p_o->p_adresa->cislo,
          p_o->plat);

  free((void *) lide[0].p_jmeno);
  free((void *) lide[0].p_adresa->p_ulice);
  free((void *) lide[0].p_adresa);
  free((void *) lide[1].p_jmeno);
  free((void *) lide[1].p_adresa);

  return 0;
}

