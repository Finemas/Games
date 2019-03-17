/*
 * cv09a.c    v.2.0
 *
 * Presmerovani vystupu na obrazovku nebo do souboru
 * =================================================
 *
 * Verze pro realny provoz s osetrenim chybovych stavu
 * ---------------------------------------------------
 *
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
  FILE *fr, *fw;
  int c;

  if ((fr = fopen("PISMENA.TXT", "r")) == NULL)  {
    printf("Soubor PISMENA.TXT se nepodarilo otevrit\n");
    return 1;
  }

  printf("Vystup na obrazovku nebo do souboru [O / S]: ");

  /* cekani na stisteni znaku 'o' nebo 'O' nebo 's' nebo 'S' */
  while ((c = toupper(getchar())) != 'O'  &&  c != 'S') {
    while (getchar() != '\n')
      ;
    printf("[O / S]: ");
  }

  if (c == 'O')
    fw = stdout;
  else {
    if ((fw = fopen("NOVY.TXT", "w")) == NULL) {
      printf("Soubor NOVY.TXT se nepodarilo otevrit\n");

      /* uzavreni otevreneho souboru PISMENA.TXT */
      if (fclose(fr) == EOF)
        printf("Soubor PISMENA.TXT se nepodarilo uzavrit\n");

      /* ukonceni programu */
      return 1;
    }
  }

  /* cteni a kopirovani souboru */
  while ((c = getc(fr)) != EOF)
    putc(c, fw);

  /* uzavreni souboru */
  if (fclose(fr) == EOF)
    printf("Soubor PISMENA.TXT se nepodarilo uzavrit\n");
  if (fclose(fw) == EOF)
    printf("Soubor NOVY.TXT se nepodarilo uzavrit\n");

  return 0;
}

