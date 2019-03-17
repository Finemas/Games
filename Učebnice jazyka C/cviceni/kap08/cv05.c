/*
 * cv05.c    v.2.0
 *
 * Definice vlastnich maker pro praci se znaky a tisk ASCII tabulky
 * ================================================================
 *
 */

#include <stdio.h>

#define HORNI_MEZ  127

#define lze_tisknout(c)  (((c) >= ' '  &&  (c) < HORNI_MEZ) ? 1 : 0)

int main(void)
{
  int i;

  printf("ASCII tabulka :\n");
  printf("===============\n\n");

  for (i = 0;  i < HORNI_MEZ;  i++) {
    if (lze_tisknout(i))
      printf("%3d %c   ", i, i);
    else
      printf("%3d -?- ", i);
  }
  putchar('\n');
  return 0;
}

