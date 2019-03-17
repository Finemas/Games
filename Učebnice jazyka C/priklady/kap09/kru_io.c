/*
 * kru_io.c    ver. 2.0
 *
 * Vstupy a vystupy programu pro vypocty kruznice
 * ==============================================
 *
 * P. Herout,  rijen 2003
 */
/* systemove hlavickove soubory */
#include <stdio.h>

/* vlastni hlavickove soubory */
#include "kru_io.h"     /* natazeni symbolickych konstant,
                           funkcnich prototypu globalnich funkci
                           a globalnich typu vlastniho modulu */
#include "kru_main.h"   /* natazeni symbolickych konstant,
                           funkcnich prototypu globalnich funkci
                           a globalnich typu spolupracujiciho
                           modulu */

/* definice globalnich promennych */
  /* v tomto modulu zadne nejsou */

/* lokalni definice symbolickych konstant a maker */
#define kontrola(x)    ( ((x) >= 0.0) ? (x) : CHYBA_DAT )

/* lokalni definice novych typu */
  /* v tomto modulu zadne nejsou */

/* definice statickych globalnich promennych */
static double polomer;

/* uplne funkcni prototypy lokalnich funkci */
  /* v tomto modulu zadne nejsou */
/* funkce main() */
  /* v tomto modulu neni */

/* definice lokalnich funkci */
  /* v tomto modulu zadne nejsou */

/* definice globalnich funkci */
double vstup_dat(void)
{
  printf("\nZadej polomer kruznice (kladne realne cislo): ");
  scanf("%lf", &polomer);

  return (kontrola(polomer));
}

void vystup_dat(double obsah)
{
  double prumer;

  printf("Obsah kruhu o polomeru %6.2f je %.2f\n",
          polomer, obsah);

  prumer = vyp_prumeru(polomer);
  printf("Obvod kruhu o prumeru  %6.2f je %.2f\n",
          prumer, obvod);
}

