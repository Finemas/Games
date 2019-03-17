/*
 * s112a.c    v.2.0
 *
 * Funkce bez navratove hodnoty
 * ============================
 */

#include <stdio.h>

void tisk_int(int i)
{
  printf("%d", i);
}

int main()
{
  int j = 2;

  tisk_int(1);
  putchar('\n');
  tisk_int(j);
  return 0;
}

