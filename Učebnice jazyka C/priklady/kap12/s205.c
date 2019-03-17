/*
 * s205.c    v.2.0
 *
 * Pouziti funkce puts()
 * =====================
 */

#include <stdio.h>

int main(void)
{
  int i;
  char ahoj[] = "ahoj lidi, jak se mate";
/*  fclose(stdout); */
  i = puts(ahoj);

  fprintf(stderr, "i = %d\n", i);

  return 0;
}

