/*
 * cv10.c    v.2.0
 *
 * Kopirovani souboru - jmena souboru jsou parametry vstupni radky
 * ===============================================================
 */

#include <stdio.h>
#include <ctype.h>

#define MAX  100
/* uplny funkcni prototyp */
void vypis_souboru(FILE *fr, FILE *fw);
void vypis_napovedy(char *p_jmeno);

int main(int argc, char *argv[])
{
  FILE *fr, *fw;
  char jmeno[MAX];

  if (argc == 2) {
    if (argv[1][0] == '-'  &&  toupper(argv[1][1]) == 'H') {
      vypis_napovedy(argv[0]);
      return 0;
    }
  }

  if (argc == 1) {
    printf("Zadej jmeno vypisovaneho souboru: ");
    scanf("%100s", jmeno);
  }
  else {
    strcpy(jmeno, argv[1]);
  }

  if (argc == 1  ||  argc == 2) {
    /* vypis souboru */
    if ((fr = fopen(jmeno, "r")) == NULL) {
      printf("Soubor '%s' nelze otevrit\n", jmeno);
      return 1;
    }

    vypis_souboru(fr, stdout);

    if (fclose(fr) == EOF)
      printf("Soubor '%s' nelze uzavrit\n", jmeno);
  }
  else {
    /* kopirovani souboru */
    if ((fr = fopen(jmeno, "r")) == NULL) {
      printf("Soubor '%s' nelze otevrit\n", jmeno);
      return 1;
    }
    if ((fw = fopen(argv[2], "w")) == NULL) {
      printf("Soubor '%s' nelze otevrit\n", argv[2]);
      return 1;
    }

    vypis_souboru(fr, fw);

    if (fclose(fr) == EOF)
      printf("Soubor '%s' nelze uzavrit\n", jmeno);
    if (fclose(fw) == EOF)
      printf("Soubor '%s' nelze uzavrit\n", argv[2]);
  }

  return 0;
}


/*
 * kopirovani souboru
 */

void vypis_souboru(FILE *fr, FILE *fw)
{
  int c;
  while (c = fgetc(fr), feof(fr) == 0)
    fputc(c, fw);
}


/*
 * vypis napovedy
 */

void vypis_napovedy(char *p_jmeno)
{
  printf("\nPouziti:\n"
         "=========\n"
         "%s\n"
         "      - vypis teto napovedy\n\n"
         "%s vstupni-soubor\n"
         "      - vypis souboru na obrazovku\n\n"
         "%s vstupni-soubor vystupni-soubor\n"
         "      - kopirovani souboru\n", p_jmeno, p_jmeno, p_jmeno);
}

