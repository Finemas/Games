/*
 * cv14.c    v.2.0
 *
 * Vypocet faktorialu
 * ==================
 *
 */

#include <stdio.h>

int main(void)
{
  long int n,                   /* stupen faktorialu */
           fakt = 1,            /* hodnota faktorialu */
           i;

  printf("Zadej stupen faktorialu: ");
  scanf("%ld", &n);

  for (i = 2;  i <= n;  i++) {
    fakt *= i;
  }
  printf("\nFaktorial cisla %ld je %ld\n", n, fakt);
  return 0;
}

