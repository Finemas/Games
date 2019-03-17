/*
 * s157a.c    v.2.0
 *
 * Pointer na funkci vracejici double
 * ==================================
 */

#include <stdio.h>

#define DOLNI  (-1)
#define HORNI  1
#define KROK   0.2

double pol1(double x)
{
  return (x * x + 8);
}

double pol2(double x)
{
  return (x * x * x - 3);
}

int main(void)
{
  int i;
  double x;
  double (*p_fd)();   /* pointer na funkci vracejici double */

  for (i = 0;  i < 2;  i++) {
    /* prirazeni adresy funkce pointeru fd */
    p_fd = (i == 0) ? pol1 : pol2;
    /* tabulace */
    for (x = DOLNI;  x <= HORNI;  x += KROK)
      printf("%5.1f %8.3f\n", x, p_fd(x));

    putchar('\n');           /* odradkovani */
  }
  return 0;
}

