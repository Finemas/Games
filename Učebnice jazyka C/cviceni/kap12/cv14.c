/*
 * cv14.c    v.2.0
 *
 * Retezcova promenna jako ridici retezec formatu
 * ==============================================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  100             /* max. delka retezce */

#define PI  3.141592653589

int main(void)
{
  char format[MAX];
  int  pocet;

  do {
    printf("Zadej pocet desetinnych mist [0 = konec]: ");
    scanf("%d", &pocet);
    sprintf(format, "Pi na %d desetinnych mist: %%.%df\n", pocet, pocet);
    printf(format, PI);
  } while (pocet != 0);

  /* jiny - trochu jednodussi zpusob */
  do {
    printf("Zadej pocet desetinnych mist [0 = konec]: ");
    scanf("%d", &pocet);
    printf("Pi na %d desetinnych mist: %.*f\n", pocet, pocet, PI);
  } while (pocet != 0);

  return 0;
}

