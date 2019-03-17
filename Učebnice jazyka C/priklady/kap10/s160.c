/*
 * s160.c    v.2.0
 *
 * Pointer na funkci jako navratovy typ funkce
 * ===========================================
 */

#include <stdio.h>
#include <math.h>

typedef double (*P_FD)();

P_FD g(void)
{
  return (sqrt);
}

int main(void)
{
  double d = g()(9.0);

  printf("d = %f\n", d);

  return 0;
}

