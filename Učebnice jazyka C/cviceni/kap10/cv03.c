/*
 * cv03.c    v.2.0
 *
 * Vypis libovolneho souboru vcetne jeho delky
 * ===========================================
 *
 */

#include <stdio.h>

/* uplny funkcni prototyp */
long cti_znak(FILE *fr, int *p_c);

int main(void)
{
  FILE *fr;
  long int akt_pocet;
  char jmeno[100];
  int c;

  printf("Zadej jmeno souboru: ");
  scanf("%s", jmeno);
  if ((fr = fopen(jmeno, "r")) == NULL) {
    printf("Soubor %s nebyl otevren.\n", jmeno);
    return 1;
  }

  while (1) {
    akt_pocet = cti_znak(fr, &c);
    if (c == EOF)
      break;
    else
      putchar(c);
  }

  printf("\n\nV souboru bylo %ld znaku\n", akt_pocet - 1);

  if (fclose(fr) == EOF)
    printf("Soubor %s nebyl zavren.\n", jmeno);

  return 0;
}


/*
 * cteni znaku ze souboru
 */

long cti_znak(FILE *fr, int *p_c)
{
  static long int pocet = 0;

  *p_c = getc(fr);
  return (++pocet);
}

