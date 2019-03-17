/*
 * cv06.c    v.2.0
 *
 * Adresa retezcove konstanty
 * ==========================
 *
 */

#include <stdio.h>

int main(void)
{
  char *p_s = "Konstanta 1";

  printf("Adresa 1.retezcove konstanty \"%s\" je %p\n", p_s, p_s);
  printf("Adresa 2.retezcove konstanty je %p\n", "Konstanta 2");

  return 0;
}

