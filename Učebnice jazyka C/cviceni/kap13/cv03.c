/*
 * cv03.c    v.2.0
 *
 * Ulozeni souboru do pameti a zapis do druheho souboru pozpatku
 * =============================================================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000                /* max. pocet radek */
#define MAX_DELKA_RADKY   80    /* max. delka p_radky v souboru */
#define VYSTUPNI  "OBRACENY.TXT"

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
      printf("\007Malo dynamicke pameti\n");
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
  char jmeno_souboru[100];

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno_souboru);

  if ((fr = fopen(jmeno_souboru, "r")) == NULL) {
    printf("Soubor '%s' nelze otevrit.\n", jmeno_souboru);
    return 1;
  }

  /* nacteni souboru do pameti */
  pocet = nacti_soubor(fr);

  if (fclose(fr) == EOF) {
    printf("Soubor '%s' nelze uzavrit.\n", jmeno_souboru);
  }

  /* zapis do vystupniho souboru pozpatku */
  if ((fw = fopen(VYSTUPNI, "w")) == NULL) {
    printf("Soubor '%s' nelze otevrit\n", VYSTUPNI);
    return 1;
  }

  for (i = pocet - 1;  i >= 0;  i--) {
    fprintf(fw, "%s", p_radky_souboru[i]);
  }

  if (fclose(fw) == EOF) {
    printf("Soubor '%s' nelze uzavrit.\n", VYSTUPNI);
  }

  return 0;
}

