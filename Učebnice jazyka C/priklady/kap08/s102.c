/*
 * s102.c    v.2.0
 *
 * Podmineny preklad rizeny hodnotou konstantniho vyrazu
 * =====================================================
 */

#include <stdio.h>

#define WINDOWS  1

#if WINDOWS
  #define JMENO   "D:\\data\\senzor.txt"
#else
  #define JMENO   "/data/senzor.txt"
#endif

int main()
{
  FILE *fr;

  /* prace se souborem nezavisla na operacnim systemu */
  if ((fr = fopen(JMENO, "r")) == NULL) {
    printf("Soubor '%s' se nepodarilo otevrit\n", JMENO);
    return 1;
  }

  /* zde by se zpracovaval soubor */

  fclose(fr);
  return 0;
}

