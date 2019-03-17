/*
 * cv09.c    v.2.0
 *
 * Kopirovani souboru - jmena souboru jsou parametry vstupni radky
 * ===============================================================
 */

#include <stdio.h>
#include <ctype.h>

/* uplny funkcni prototyp */
void vypis_souboru(FILE *fr, FILE *fw);
void vypis_napovedy(char *p_jmeno);

int main(int argc, char *argv[])
{
  int  i;
  FILE *fr, *fw;

  switch (argc) {
    case 1 :
      vypis_napovedy(argv[0]);
      break;

    case 2 :
      if ((fr = fopen(argv[1], "r")) == NULL) {
        printf("Soubor '%s' nelze otevrit\n", argv[1]);
        break;
      }

      vypis_souboru(fr, stdout);

      if (fclose(fr) == EOF)
        printf("Soubor '%s' nelze uzavrit\n", argv[1]);
      break;

    case 3 :
      if ((fr = fopen(argv[1], "r")) == NULL) {
        printf("Soubor '%s' nelze otevrit\n", argv[1]);
        break;
      }
      if ((fw = fopen(argv[2], "w")) == NULL) {
        printf("Soubor '%s' nelze otevrit\n", argv[2]);
        break;
      }

      vypis_souboru(fr, fw);

      if (fclose(fr) == EOF)
        printf("Soubor '%s' nelze uzavrit\n", argv[1]);
      if (fclose(fw) == EOF)
        printf("Soubor '%s' nelze uzavrit\n", argv[2]);
      break;
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

