/*
 * cv13.c    v.2.0
 *
 * Test prikazu break a continue
 * =============================
 *
 */

#include <stdio.h>

int main(void)
{
  int i;

  printf("\nTest prikazu break a continue\n");

  for (i = 1;  i < 20;  i++) {
    printf("\n%d ", i);
    if (i >= 15) {
      printf("break\n");
      break;
    }
    if (i >= 10) {
      printf("continue ");
      continue;
    }
    printf("posledni prikaz cyklu for");
  }
  return 0;
}

