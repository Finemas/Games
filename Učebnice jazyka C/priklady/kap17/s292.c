/*
 * s291.c    v.2.0
 *
 * Kopirovani souboru po blocich
 * =============================
 */

#include <stdio.h>
#include <stdlib.h>

#define DELKA_BLOKU  5

int main(void)
{
  char blok[DELKA_BLOKU];
  FILE *fr, *fw;
  int precteno;

  fr = fopen("A.TXT", "rb");
  fw = fopen("B.TXT", "wb");

  while ((precteno = fread(blok, sizeof(char), DELKA_BLOKU, fr))
         == DELKA_BLOKU) {
    if (fwrite(blok, sizeof(char), DELKA_BLOKU, fw)
           != DELKA_BLOKU) {
      fprintf(stderr, "Chyba pri zapisu do souboru\n");
      exit(1);
    }
  }
  /* cteni skoncilo prectenim vseho nebo chybou */

  if (ferror(fr) != 0) {
    fprintf(stderr, "Chyba ve cteni souboru\n");
  }
  else {
    /* skoncil prectenim mene dat, nez je velikost bloku */
    /* prectena data je nutno zapsat, i kdyz jich je mene */
    if (fwrite(blok, sizeof(char), precteno, fw) != precteno)
      fprintf(stderr, "Chyba pri zapisu do souboru\n");
  }

  fclose(fr);
  fclose(fw);
  return 0;
}

