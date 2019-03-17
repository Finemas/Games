/*
 * s343.c    v.2.0
 *
 * Pouziti systemovych prikazu z programu
 * ======================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  printf("Vyvolani prikazu DIR z programu\n");
  system("dir *.c");
  return 0;
}

