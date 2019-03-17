/*
 * cv04.c    v.2.0
 *
 * Ulozeni souboru do pameti a vypis radek obsahujicich zadane slovo
 * =================================================================
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000                /* max. pocet radek */
#define MAX_DELKA_RADKY   80    /* max. delka p_radky v souboru */

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
  FILE *fr;
  char jmeno_souboru[100];
  char slovo[100];

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

  while (1) {
    printf("Zadej hledane slovo [K = konec]: ");
    scanf("%19s", slovo);
    if (toupper(slovo[0]) == 'K'  &&  strlen(slovo) == 1)
      break;

    /* hledani a vypis */
    for (i = 0;  i < pocet;  i++) {
      if (strstr(p_radky_souboru[i], slovo) != NULL)
        printf("%s", p_radky_souboru[i]);
    }
  }
  return 0;
}

