/*
 * cv04.c    v.2.0
 *
 * Bitove pole - pouziti pro ulozeni zhusteneho cisla
 * ==================================================
 */

#include <stdio.h>

typedef struct {
  unsigned den    : 5;   /* bity 0 -  4 */
  unsigned mesic  : 4;   /* bity 5 -  8 */
  unsigned rok    : 7;   /* bity 9 - 15 */
} DATUM;

typedef union {
  DATUM         datum;
  unsigned int  cislo;
} BITY;

int main(void)
{
  BITY dnes;
  int den, mesic, rok;

  printf("Zadej dnesni datum [dd mm rrrr]: ");
  scanf("%d %d %d", &den, &mesic, &rok);

  dnes.cislo = 0;
  printf("datum: %2d.%2d.%4d - cislo: %04X hexa\n",
          dnes.datum.den, dnes.datum.mesic, dnes.datum.rok + 1980,
          dnes.cislo);

  dnes.datum.den = den;
  printf("datum: %2d.%2d.%4d - cislo: %04X hexa\n",
          dnes.datum.den, dnes.datum.mesic, dnes.datum.rok + 1980,
          dnes.cislo);

  dnes.datum.mesic = mesic;
  printf("datum: %2d.%2d.%4d - cislo: %04X hexa\n",
          dnes.datum.den, dnes.datum.mesic, dnes.datum.rok + 1980,
          dnes.cislo);

  dnes.datum.rok = rok - 1980;
  printf("datum: %2d.%2d.%4d - cislo: %04X hexa\n",
          dnes.datum.den, dnes.datum.mesic, dnes.datum.rok + 1980,
          dnes.cislo);

  return 0;
}

