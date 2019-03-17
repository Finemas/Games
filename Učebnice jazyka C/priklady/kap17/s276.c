/*
 * s276.c    v.2.0
 *
 * Ruzne rezimy otvirani souboru
 * =============================
 */

#include <stdio.h>

int main(void)
{
  FILE *fr, *fw;
  char rezim[3];
  int c;

  printf("Zadej rezim zapisu: ");
  scanf("%2s", rezim);
  fw = fopen("A.DAT", rezim);
  putc('a', fw); putc('\n', fw); putc('b', fw); putc('\r', fw);
  putc('c', fw); putc('\n', fw); putc('\r', fw); putc('d', fw);
  fclose(fw);

  printf("Zadej rezim cteni: ");
  scanf("%2s", rezim);
  fr = fopen("A.DAT", rezim);
  while ((c = getc(fr)) != EOF)
    printf("%02X ", c);
  fclose(fr);
  return 0;
}

