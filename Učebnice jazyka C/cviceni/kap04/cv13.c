/*
 * cv13.c    v.2.0
 *
 * Formatovane cteni a nasobeni realnych cisel
 * ===========================================
 *
 */

#include <stdio.h>

int main(void)
{
  double x, y, z;

  printf("Zadej 3 realna cisla: ");
  scanf("%lf %lf %lf", &x, &y, &z);
  printf("Aritmeticky prumer je: %.2f\n", (x + y + z) / 3);
  return 0;
}

