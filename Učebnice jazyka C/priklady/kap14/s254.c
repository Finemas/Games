/*
 * s254.c    v.2.0
 *
 * Hodnota polozky vyctoveho typu
 * ==============================
 */

#include <stdio.h>

typedef enum {
  MODRA = 0,
  CERVENA = 4,
  ZELENA = 2,
  ZLUTA                         /* neinicializovano */
} BARVY;

int main(void)
{
  BARVY c;

  c = ZLUTA;
/*  printf("Barva byla %s\n", c);      /* chybne */
  printf("Barva mela cislo %d\n", (int) c);
  return 0;
}

