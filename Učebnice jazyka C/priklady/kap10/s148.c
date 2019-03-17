/*
 * s148.c    v.2.0
 *
 * Prirazeni adresy promenne pointeru
 * ==================================
 */

#include <stdio.h>

int main(void)
{
  int i, j, *p_i;

  scanf("%d %d", &i, &j);
  p_i = (i > j) ? &i : &j;
  printf("Vetsi je %d\n", *p_i);
  return 0;
}

