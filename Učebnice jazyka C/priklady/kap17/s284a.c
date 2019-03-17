/*
 * s284a.c    v.2.0
 *
 * Jednotny test chyby pri zpracovani souboru
 * ==========================================
 */

#include <stdio.h>

#define ERR_STAV   1

int stav_souboru(FILE *f)
{
  int stav = 0;
  if (ferror(f) != 0)
    stav = ERR_STAV;
  clearerr(f);
  return stav;
}

int main(void)
{
  FILE *fr;
  int c, stav;

  if ((fr = fopen("A.DAT", "r")) == NULL) {
    printf("Soubor A.DAT se nepodarilo otevrit.\n");
    return 1;
  }

  do {
    c = getc(fr);
    stav = stav_souboru(fr);
    printf("Bajt - %02X, chyba - %s\n", c,
	    (stav != 0) ? "ANO" : " NE");
    fr = stdout;         /* zmena pointeru simuluje chybu */
  } while (c != EOF  &&  stav != ERR_STAV);

  if (fclose(fr)) {
    printf("Soubor A.DAT se nepodarilo uzavrit.\n");
    return 1;
  }
  return 0;
}

