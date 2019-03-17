/*
 * cv09.c    v.2.0
 *
 * Zkracene vyhodnocovani podminky &&
 * ==================================
 *
 */

#include <stdio.h>

int main(void)
{
  int i, j;

  i = 4;
  j = 1;
  printf("podminka: (i == 5  &&  ++j == 3)\n\n");
  printf("Pred podminkou: i = %d  j = %d\n", i, j);
  if (i == 5  &&  ++j == 3)
    printf("podminka platna\n");
  else
    printf("podminka NEplatna\n");
  printf("Po podmince:    i = %d  j = %d\n\n", i, j);

  i = 5;
  j = 2;
  printf("Pred podminkou: i = %d  j = %d\n", i, j);
  if (i == 5  &&  ++j == 3)
    printf("podminka platna\n");
  else
    printf("podminka NEplatna\n");
  printf("Po podmince:    i = %d  j = %d\n\n", i, j);
  return 0;
}

