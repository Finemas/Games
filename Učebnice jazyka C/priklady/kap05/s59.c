/*
 * s59.c    v.2.0
 *
 * Moznosti cyklu for
 * ==================
 */

#include <stdio.h>

int main()
{
  int i = 0,
      soucin, sum;

  for (i = 0;  i < 10;  i++)
    printf("%d ", i);


  putchar('\n');
  i = 0;                  /* nahrada za inicializaci */

  for ( ;  i < 10;  i++)
    printf("%d ", i);


  putchar('\n');
  i = 0;                  /* nahrada za inicializaci */

  for ( ;  i < 10; )
    printf("%d ", i++);


  putchar('\n');
  i = 0;                  /* nahrada za inicializaci */

  for ( ;  i < 10;  printf("%d ", i), i++)
    ;

  putchar('\n');

  for (i = 1, sum = 0;  i <= 10;  sum += i, i++)
     ;
  printf("sum = %d\n", sum);

  for (i = 3, soucin = 1;  i <= 9;  i += 2)
    soucin *= i;
  printf("soucin = %d\n", soucin);
  return 0;
}
