/*
 * cv01.c    v.2.0
 *
 * Pocet pismen v souboru - pomoci radkoveho histogramu
 * ====================================================
 *
 */

#include <stdio.h>
#include <ctype.h>

#define MAX   ('Z' - 'A' + 1)

/* uplny funkcni prototyp */
void zjisteni_poctu(FILE *fr, int pocty[]);
void vypis_histogramu(int pocty[]);

int main(void)
{
  FILE *fr;
  int  pocty[MAX];
  char jmeno[100];
  int c;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor %s nebyl otevren.\n", jmeno);
    return 1;
  }

  zjisteni_poctu(fr, pocty);

  if (fclose(fr) == EOF)
    printf("Soubor %s nebyl zavren.\n", jmeno);

  vypis_histogramu(pocty);

  return 0;
}


/*
 * zjisteni poctu pismen v souboru
 */

void zjisteni_poctu(FILE *fr, int pocty[])
{
  int c, i;

  /* nulovani pole pocty[] */
  for (i = 0;  i < MAX;  i++) {
    pocty[i] = 0;
  }

  while ((c = getc(fr)) != EOF) {
    if (isalpha(c) != 0) {
      /* je to pismeno */
      i = toupper(c) - 'A';     /* prevedeni na velka pismena a index */
      pocty[i]++;
    }
  }
}

/*
 * vypise radkovy histogram
 */

void vypis_histogramu(int pocty[])
{
  int i, j;

  printf("Pocty pismen v souboru:\n"
         "=======================\n");
  for (i = 0;  i < MAX;  i++) {
    printf("%c: %2d ", i + 'A', pocty[i]);
    for (j = 0;  j < pocty[i];  j++) {
      putchar('*');
    }
    putchar('\n');              /* odradkovani po kazde radce */
  }
}

