/*
 * cv07.c    v.2.0
 *
 * Rozliseni cislic, malych a velkych pismen a ostatnich znaku
 * ===========================================================
 *
 * P.Herout   10.1991
 *
 */

#include <stdio.h>

int main(void)
{
  int c;

  printf("Zadej jeden znak: ");
  c = getchar();

  if (c >= '0'  &&  c <= '9')
    printf("Cislice: '%c'\n", c);
  else if (c >= 'A'  &&  c <= 'Z')
    printf("Velke pismeno: '%c'\n", c);
  else if (c >= 'a'  &&  c <= 'z')
    printf("Male pismeno: '%c'\n", c);
  else
    printf("Interpunkcni znak: '%c'\n", c);
  return 0;
}

