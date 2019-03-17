/*
 * cv02.c    v.2.0
 *
 * Pokusy se statickou a dynamickou strukturou
 * ===========================================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELKA_JM   30     /* delka jmena */

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
  CLOVEK ja;
  CLOVEK *p_ona;

  napln(&ja, "Pavel", 30);

  /* alokovani pameti pro dynamickou strukturu */
  if ((p_ona = (CLOVEK *) malloc(sizeof(CLOVEK))) == NULL) {
    printf("\nMalo pameti!\n");
    return 1;
  }
  napln(p_ona, "Katerina", 2);

  /* tisk obsahu obou struktur */
  printf("Jmenujeme se %s a %s\n", ja.jmeno, p_ona->jmeno);
  printf("Jsme stari %u a %u let\n", ja.stari, p_ona->stari);

  return 0;
}

