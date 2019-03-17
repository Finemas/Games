/*
 * cv08.c    v.2.0
 *
 * Test existence souboru
 * ======================
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
  NE, ANO
} BOOLEAN;

/*
 * test existence souboru
 */
BOOLEAN je_tu(char *jmeno)
{
  FILE  *fr;

  if ((fr = fopen(jmeno, "r")) != NULL) {
    fclose(fr);
    return (ANO);
  }
  else
    return (NE);
}

int main(void)
{
  char  jmeno_souboru[100];

  while (1) {
    printf("Zadej jmeno souboru [K = konec]: ");
    scanf("%s", jmeno_souboru);

    if (strlen(jmeno_souboru) == 1  &&  toupper(jmeno_souboru[0]) == 'K') {
      break;                    /* konec testu souboru */
    }
    else {
      if (je_tu(jmeno_souboru) == ANO) {
        printf("Soubor '%s' existuje\n", jmeno_souboru);
      }
      else {
        printf("Soubor '%s' neni na disku\n", jmeno_souboru);
      }
    }
  }

  return 0;
}

