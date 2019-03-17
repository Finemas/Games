/*
 * s208.c    v.2.0
 *
 * Pouziti funkce fputs()
 * ======================
 */

#include <stdio.h>

int main(void)
{
  FILE *fr = stdout;
  int i;
  char ahoj[] = "ahoj lidi, jak se mate\n";
/*   fr = fopen("dopis.txt", "r");  */
  /* pokus o zapis do souboru pro cteni */
  i = fputs(ahoj, fr);

  printf("i = %d\n", i);

  return 0;
}

