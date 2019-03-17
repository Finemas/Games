/*
 * cv01.c    v.2.0
 *
 * Velikosti zakladnich typu pomoci sizeof
 * =======================================
 *
 */

#include <stdio.h>

int main(void)
{
  printf("Velikosti zakladnich typu v Bytech\n");
  printf("==================================\n");

  printf("char        %2d\n", sizeof(char));
  printf("short       %2d\n", sizeof(short));
  printf("int         %2d\n", sizeof(int));
  printf("long        %2d\n", sizeof(long));
  printf("float       %2d\n", sizeof(float));
  printf("double      %2d\n", sizeof(double));
  printf("long double %2d\n", sizeof(long double));

  return 0;
}

