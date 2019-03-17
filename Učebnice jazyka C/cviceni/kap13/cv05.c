/*
 * cv05.c    v.2.0
 *
 * Ulozeni souboru do pameti a vytvareni rejstriku
 * ===============================================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000                /* max. pocet radek */
#define MAX_DELKA_RADKY   80    /* max. delka p_radky v souboru */

#define VSTUPNI   "SLOVA.TXT"
#define VYSTUPNI  "ODKAZY.TXT"

char *p_radky_souboru[MAX];     /* pole pointeru na p_radky */

/*
 * nacte soubor po radcich do pameti do pole p_radky
 */
int nacti_soubor(FILE *fr)
{
  int i = 0;
  char radka[MAX_DELKA_RADKY];

  while (fgets(radka, MAX_DELKA_RADKY - 1, fr) != NULL) {
    /* alokovani pameti pro ulozeni nactene p_radky + '\0' */
    if ((p_radky_souboru[i] = (char *) malloc(strlen(radka) + 1)) == NULL) {
      printf("Malo dynamicke pameti.\n");
      return (++i);
    }
    strcpy(p_radky_souboru[i++], radka);
  }
  return i;
}


int main(void)
{
  int  pocet;                   /* skutecny pocet radek */
  int  i;
  FILE *fr, *fw;
  char jmeno_souboru[20];
  char slovo[MAX_DELKA_RADKY];

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno_souboru);

  if ((fr = fopen(jmeno_souboru, "r")) == NULL) {
    printf("Soubor %s nelze otevrit.\n", jmeno_souboru);
    return 1;
  }

  /* nacteni souboru do pameti */
  pocet = nacti_soubor(fr);

  if (fclose(fr) == EOF) {
    printf("Soubor %s nelze uzavrit.\n", jmeno_souboru);
  }

  /* vytvareni rejstriku */
  if ((fr = fopen(VSTUPNI, "r")) == NULL) {
    printf("Soubor '%s' nelze otevrit.\n", VSTUPNI);
    return 1;
  }

  if ((fw = fopen(VYSTUPNI, "w")) == NULL) {
    printf("Soubor '%s' nelze otevrit.\n", VYSTUPNI);
    return 1;
  }

  while (fgets(slovo, MAX_DELKA_RADKY - 1, fr) != NULL) {
    /* ubrani ukoncujiciho znaku '\n' */
    slovo[strlen(slovo) - 1] = '\0';

    if (strlen(slovo) > 0) {
      /* hledani slova a zapis do vystupniho souboru */
      fprintf(fw, "%s:", slovo);
      for (i = 0;  i < pocet;  i++) {
        if (strstr(p_radky_souboru[i], slovo) != NULL)
          fprintf(fw, " %3d,", i + 1);
      }
      fputc('\n', fw);
    }
  }

  if (fclose(fr) == EOF) {
    printf("Soubor '%s' nelze uzavrit.\n", VSTUPNI);
  }
  if (fclose(fw) == EOF) {
    printf("Soubor '%s' nelze uzavrit.\n", VYSTUPNI);
  }

  return 0;
}

