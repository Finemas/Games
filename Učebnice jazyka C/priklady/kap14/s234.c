/*
 * s234.c    v.2.0
 *
 * Prace s celymi strukturami najednou
 * ===================================
 */

#include <stdio.h>

typedef struct {     /* definice struktury jejimz  */
  int a[10];         /* jedinym prvkem je pole int */
} STR_POLE;

typedef struct miry {
  int   vyska;
  float vaha;
} MIRY;

int main(void)
{
  MIRY pavel, honza;
  STR_POLE  aaa, bbb;

  pavel.vyska = 186;
  aaa.a[1] = 5;
  honza = pavel;
  bbb = aaa;

  printf("Honza vyska %d\n", honza.vyska);
  printf("bbb.a[1] = %d\n", bbb.a[1]);
  return 0;
}

