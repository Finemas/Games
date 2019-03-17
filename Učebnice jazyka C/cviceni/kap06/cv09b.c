/*
 * cv09b.c    v.2.0
 *
 * Presmerovani vystupu na obrazovku nebo do souboru
 * =================================================
 *
 * Verze bez jakychkoliv osetreni moznych chybovych stavu
 * ------------------------------------------------------
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr, *fw;
  int c;

  fr = fopen("PISMENA.TXT", "r");

  printf("Vystup na obrazovku nebo do souboru [o / s]: ");
  c = getchar();
  if (c == 'o')
    fw = stdout;
  else
    fw = fopen("NOVY.TXT", "w");

  while ((c = getc(fr)) != EOF)
    putc(c, fw);

  fclose(fr);
  fclose(fw);

  return 0;
}

