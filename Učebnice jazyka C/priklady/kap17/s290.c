/*
 * s290.c    v.2.0
 *
 * Kopirovani souboru po bajtech
 * =============================
 */

#include <stdio.h>

int main(void)
{
  FILE *fr, *fw;
  int c;

  fr = fopen("A.DAT", "rb");
  fw = fopen("B.DAT", "wb");

  while ((c = getc(fr)) != EOF)
    putc(c, fw);

  fclose(fr);
  fclose(fw);
  return 0;
}

