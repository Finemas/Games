/*
 * cv10.c    v.2.0
 *
 * Vypis polozek inicializovaneho vyctoveho typu
 * =============================================
 *
 */

#include <stdio.h>

typedef enum {
  FORD     = 23,
  TOYOTA   = 51,
  RENAULT,
  SKODA    = 35,
  FIAT     = 40
} AUTOMOBILY;

/*
 * vytiskne cislo a jmeno automobilu
 */

void tiskni(AUTOMOBILY cislo)
{
  printf("%d. ", cislo);
  switch (cislo) {
    case FORD :
      printf("Ford");
      break;

    case TOYOTA :
      printf("Toyota");
      break;

    case RENAULT :
      printf("Renault");
      break;

    case SKODA :
      printf("Skoda");
      break;

    case FIAT :
      printf("Fiat");
      break;
  }
  putchar('\n');
}

int main(void)
{
  AUTOMOBILY auta;

  printf("Muzete si koupit tato auta:\n");
  auta = FORD;
  tiskni(auta);
  tiskni(TOYOTA);
  tiskni(RENAULT);
  tiskni(SKODA);
  tiskni(FIAT);

  return 0;
}

