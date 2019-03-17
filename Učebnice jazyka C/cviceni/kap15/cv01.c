/*
 * cv01.c    v.2.0
 *
 * Zjisteni delky typu int v bitech
 * ================================
 *
 *
 */

#include <stdio.h>


/*
 * zjisti delku int v bitech
 */
int delka_int(void)
{
  unsigned int x,
               i = 0;

  x = ~0;

  while ((x >>= 1) != 0)
    i++;

  return (++i);
}


int main(void)
{
  printf("Delka typu int je %d bitu\n", delka_int());

  return 0;
}

