/*
 * s150.c    v.2.0
 *
 * Zpetna konverze pointeru
 * ========================
 */

#include <stdio.h>

int main(void)
{
  char c;
  char *p_c = &c;
  int  *p_i;

  printf("p_c pred konverzi: %p\n", p_c);
  p_i = (int *) p_c;
  p_c = (char *) p_i;
  printf("p_c po konverzi:   %p\n", p_c);
  return 0;
}

