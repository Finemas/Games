/*
 * s244.c    v.2.0
 *
 * Ulozeni struktury v pameti
 * ==========================
 */

#include <stdio.h>

typedef struct {
  char c;
  int  i, j, k;
  char d;
} PRIKLAD;

PRIKLAD pokus[2];

int main(void)
{
  printf("Adresy: c = %p, i = %p, j = %p, k = %p, d = %p\n",
           &pokus[0].c, &pokus[0].i, &pokus[0].j, &pokus[0].k, &pokus[0].d);

  printf("Adresy: c = %p, i = %p, j = %p, k = %p, d = %p\n",
           &pokus[1].c, &pokus[1].i, &pokus[1].j, &pokus[1].k, &pokus[1].d);
  return 0;
}

