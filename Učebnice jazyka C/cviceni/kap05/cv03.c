/*
 * cv03.c    v.2.0
 *
 * Hodnota booleovskeho vyrazu
 * ===========================
 *
 */

#include <stdio.h>

int main(void)
{
  int i;

  i = 5;
  printf("%d\n", i == 8);
  printf("%d\n", i = 8);
  printf("%d\n", i == 8);
  return 0;
}

