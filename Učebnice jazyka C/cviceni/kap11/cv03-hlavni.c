/*
 * cv03-hlavni.c    v.2.0
 *
 * Pouziti pole pointeru na funkce - HLAVNI soubor
 * ===============================================
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "cv03-pozdravy.h"           /* pripojeni uplnych funkcnich prototypu */


/* definice pristupovych pointeru */
typedef void (* P_FCE)(void);    /* definice pointeru na funkci
                                    vracejici typ void */

P_FCE pozdravy[] = {ahoj, nazdar, cau, dobry_den};
char prikaz[]   = {'A',  'N',    'C', 'D',      '\0'};

int main(void)
{
  int i, c;
  char *p_c;

  printf("Ahoj    Nazdar    Cau    Dobry den    Konec\n");
  while((c = toupper(getchar())) != 'K') {
    if ((p_c = strchr(prikaz, c)) == NULL)
      continue;
    i = p_c - prikaz;
    pozdravy[i]();
  }
  return 0;
}

