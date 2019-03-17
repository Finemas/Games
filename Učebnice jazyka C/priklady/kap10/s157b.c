/*
 * s157b.c    v.2.0
 *
 * Pointer na funkci jako parametr funkce
 * ======================================
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

void tabulace(double d, double h, double k, double (*p_f)())
{
  double x;

  for (x = d;  x <= h;  x += k)
    printf("%5.1f %8.3f\n", x, p_f(x));

  putchar('\n');
}

int main(void)
{
  tabulace(DOLNI, HORNI, KROK, pol1);
  tabulace(-2.0, 2.0, 0.1, pol2);
  return 0;
}

