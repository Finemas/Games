/*
 * s255a.c    v.2.0
 *
 * Tisk nazvu polozky vyctoveho typu pomoci prepinace
 * ==================================================
 */

#include <stdio.h>

typedef enum {
  MODRA = 5,
  CERVENA = 8,
  ZELENA = 11,
  ZLUTA = 15
} BARVY;

int main(void)
{
  BARVY barva = ZLUTA;

  switch (barva) {
    case MODRA :
      printf("Byla to barva modra\n");
      break;

    case CERVENA :
      printf("Byla to barva cervena\n");
      break;

    case ZELENA :
      printf("Byla to barva zelena\n");
      break;

    case ZLUTA :
      printf("Byla to barva zluta\n");
      break;

    default :
      printf("Barva nedefinovana\n");
      break;
  }
  return 0;
}

