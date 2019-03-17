/*
 * s50a.c    v.2.0
 *
 * Logicke AND a OR
 * ================
 */

#include <stdio.h>

int main()
{
  int i = 1,
      j = 1;

  j = j  &&  (i = 2);
  printf("j = %d, i = %d\n", j, i);

  i = 1; j = 1;
  j = j  &&  (i == 3);
  printf("j = %d, i = %d\n", j, i);

  i = 1; j = 1;
  j = j  ||  (i / 2);
  printf("j = %d, i = %d\n", j, i);

  i = 1; j = 1;
  j = !j  &&  (i = i + 1);
  printf("j = %d, i = %d\n", j, i);
  return 0;
}
