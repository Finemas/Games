/*
 * s242.c    v.2.0
 *
 * Struktura ve strukture - dynamicka pamet 3.
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
  ADRESA adresa;
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
  lide[0].adresa.cislo = 10;
  lide[0].adresa.p_ulice = (char *) malloc(strlen(ulice[0]) + 1);
  strcpy(lide[0].adresa.p_ulice, ulice[0]);

  lide[1].plat = 21000.0;
  lide[1].p_jmeno = (char *) malloc(strlen("Venca") + 1);
  strcpy(lide[1].p_jmeno, "Venca");
  lide[1].adresa.cislo = 20;
  lide[1].adresa.p_ulice = ulice[1];

  printf("clovek 1: %s, %s %d, %.0f\n", lide[0].p_jmeno,
          lide[0].adresa.p_ulice, lide[0].adresa.cislo,
          lide[0].plat);

  p_o = &lide[1];
  printf("clovek 2: %s, %s %d, %.0f\n", p_o->p_jmeno,
          p_o->adresa.p_ulice, p_o->adresa.cislo,
          p_o->plat);


  free((void *) lide[0].p_jmeno);
  free((void *) lide[0].adresa.p_ulice);
  free((void *) lide[1].p_jmeno);
  return 0;
}

