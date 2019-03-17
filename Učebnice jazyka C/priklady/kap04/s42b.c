/*
 * s42b.c    v.2.0
 *
 * Cteni znaku pomoci scanf()
 * ==========================
 */

#include <stdio.h>

int main(void)
{
  char zn;
  
  printf("Zadej znak: ");
  scanf("%c", &zn);
  printf("'%c'\n", zn);
  return 0;
}
