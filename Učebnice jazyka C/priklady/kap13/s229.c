/*
 * s229.c    v.2.0
 *
 * Parametry prikazove radky
 * =======================
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;

  printf("Prikazova radka ma %d retezcu\n", argc);
  for (i = 0;  i < argc;  i++)
    printf("%s\n", argv[i]);

  return 0;
}
