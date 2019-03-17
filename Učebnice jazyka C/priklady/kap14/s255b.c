/*
 * s255a.c    v.2.0
 *
 * Tisk nazvu polozky vyctoveho typu pomoci pole retezcu
 * =====================================================
 */

#include <stdio.h>

typedef enum {
  MODRA, CERVENA, ZELENA, ZLUTA
} BARVY;

int main(void)
{
  BARVY barva = MODRA;
  char *nazvy_barev[] = { "modra", "cervena", "zelena", "zluta" };

  printf("Byla to barva %s\n", nazvy_barev[barva]);
  return 0;
}

