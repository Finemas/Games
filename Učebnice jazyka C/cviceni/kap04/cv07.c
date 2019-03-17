/*
 * cv07.c    v.2.0
 *
 * Oriznuti desetinne casti
 * ========================
 *
 */

#include <stdio.h>

int main(void)
{
  double f;
  int i;

  printf("Zadejte realne cislo s desetinnou casti: ");
  scanf("%lf", &f);
  printf("1) bez desetinne casti: %.0f - pomoci formatu tisku (!zaokrouhluje)\n", f);
  printf("2) bez desetinne casti: %d - pomoci explicitni typove konverze\n",
         (int) f);
  i = f;
  printf("3) bez desetinne casti: %d - pomoci implicitni typove konverze\n",
          i);
  return 0;
}

