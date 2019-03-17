/*
 * s203b.c    v.2.0
 *
 * Pouziti funkci sprintf() a sscanf() pro zaokrouhleni
 * ====================================================
 */

#include <stdio.h>

int main(void)
{
  double f1 = 5.1421;
  double f2 = 5.1451;
  double f;
  char pom[20];

  sprintf(pom, "%.2f", f1);
  sscanf(pom, "%lf", &f);
  printf("%f zaokrouhleno = %f\n", f1, f);

  sprintf(pom, "%.2f", f2);
  sscanf(pom, "%lf", &f);
  printf("%f zaokrouhleno = %f\n", f2, f);

  return 0;
}

