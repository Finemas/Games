/*
 * cv06.c    v.2.0
 *
 * Rozliseni alfanumerickych znaku
 * ===============================
 *
 */

#include <stdio.h>

int main(void)
{
  int c;

  printf("Zadej jeden znak: ");
  c = getchar();

  if (c >= '0'  &&  c <= '9'
      ||  c >= 'A'  &&  c <= 'Z'
      ||  c >= 'a'  &&  c <= 'z')
    printf("Alfanumericky znak\n");
  else
    printf("Interpunkcni znak\n");
  return 0;
}

