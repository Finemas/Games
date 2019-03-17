/*
 * s410.c    v.2.0
 *
 * Typ long long int
 * =================
 */

#include <stdio.h>

int main(void)
{
  long long int lli = -123456789012345LL;
  unsigned long long int llu = 123456789012345LL;

  printf("lli = %lld\n", lli);
  printf("llu = %llu\n", llu);

  printf("Zadej cele cislo:");
  scanf("%lld", &lli);
  printf("lli = %lld\n", lli);

  return 0;
}


