/*
 * cv11.c    v.2.0
 *
 * Hledani retezce v souboru
 * =========================
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX    80

typedef enum {
  FALSE, TRUE
} BOOLEAN;

/* uplny funkcni prototyp */
void vypis_radek(FILE *fr, char *slovo, BOOLEAN cisla, BOOLEAN rozl);

int main(int argc, char *argv[])
{
  FILE *fr;
  char slovo[MAX];               /* hledany retezec */
  BOOLEAN cislovat, rozlisovat;
  int i;
  char *p_c;

  /* zpracovani parametru */
  /* otevreni souboru */
  if ((fr = fopen(argv[1], "r")) == NULL) {
    printf("Soubor '%s' nelze otevrit\n", argv[1]);
    return 1;
  }


  /* zpracovani prepinacu */
  if (argc == 4) {
    /* mohou byt v poradi nc nebo cn */
    if (toupper(argv[3][0]) == 'N'  ||  toupper(argv[3][1]) == 'N')
      cislovat = TRUE;
    else
      cislovat = FALSE;

    if (toupper(argv[3][0]) == 'C'  ||  toupper(argv[3][1]) == 'C')
      rozlisovat = TRUE;
    else
      rozlisovat = FALSE;
  }
  else {
    /* 3. parametr nezadan */
    cislovat = FALSE;
    rozlisovat = FALSE;
  }

  /* zpracovani hledaneho retezce */
  i = 0;
  p_c = argv[2];
  while (*p_c != '\0') {
    slovo[i++] = (rozlisovat == TRUE) ?  *p_c  :  toupper(*p_c);
    p_c++;
  }
  slovo[i] = '\0';

  vypis_radek(fr, slovo, cislovat, rozlisovat);

  if (fclose(fr) == EOF)
    printf("Soubor '%s' nelze uzavrit\n", argv[1]);

  return 0;
}


/*
 * vypis radek souboru
 */

void vypis_radek(FILE *fr, char *slovo, BOOLEAN cisla, BOOLEAN rozl)
{
  int pocet = 0;                /* pocet radek */
  int i;
  char radka[MAX],
       upravena_radka[MAX];
  char *p_radka;

  while (fgets(radka, MAX, fr) != NULL) {
    pocet++;
    if (rozl == FALSE) {
      i = 0;
      while ((upravena_radka[i] = toupper(radka[i])) != 0) {
        i++;
      }
    }

    p_radka = (rozl == FALSE)  ?  upravena_radka  :  radka;

    if (strstr(p_radka, slovo) != NULL) {
      if (cisla == TRUE)
        printf("%3d. ", pocet);
      printf("%s", radka);
    }
  }
}

