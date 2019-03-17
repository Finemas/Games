/*
 * cv03.c    v.2.0
 *
 * Funkce pro testovani existence souboru
 * ======================================
 *
 */

#include <stdio.h>

/* #define JMENO_SOUBORU   "cv03.c"
*/
#define JMENO_SOUBORU   "test.txt"

/* uplny funkcni prototyp */
int exist(void);

int main(void)
{
  printf("Soubor %s: %s\n", JMENO_SOUBORU,
           (exist()) ? "existuje" : "neexistuje");

  return 0;
}

/*
 * existence souboru
 */

int exist(void)
{
  FILE *fr;

  if ((fr = fopen(JMENO_SOUBORU, "r")) == NULL)
    return 0;
  else {
    fclose(fr);
    return 1;
  }
}
