/*
 * s162.c    v.2.0
 *
 * Vypis pameti pomoci pointeru
 * ============================
 */

#include <stdio.h>

int main(void)
{
  double f;
  unsigned char * p_byte;
  int i;

  printf("Zadej realne cislo: ");
  scanf("%lf", &f);
  p_byte = (unsigned char *) &f;
  for (i = 0; i < sizeof(double); p_byte++, i++)
    printf("%d. byte = %02Xh\n", i, *p_byte);
  return 0;
}
