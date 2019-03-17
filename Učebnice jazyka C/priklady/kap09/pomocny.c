/*
 * pomocny.c    v.2.0
 *
 * Externi deklarace v oddelenych souborech
 * ========================================
 */

/* zacatek souboru pomocny.c */
/* prikaz:   #include <stdio.h>
   neni nutny - soubor nevyuziva I/O funkce */

int x;               /* definice  */
extern double f;     /* deklarace */

int fun(void)
{
  return (x + (int) f);
}
/* konec souboru pomocny.c */

