/*
 * s369.c    v.2.0
 *
 * Ruzne typy vystupu
 * ==================
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
   OBRAZOVKA, SOUBOR, NIC
} VYSTUP;

VYSTUP kam;      /* ovlivneni smeru vypisu */
FILE   *fw;      /* vystupni soubor */

void vypis(char *format, ...)
{
  va_list  argumenty;
  char radka[256];

  if (kam == NIC)
    return;

  va_start(argumenty, format);
  vsprintf(radka, format, argumenty);
  va_end(argumenty);

  if (kam == OBRAZOVKA) {
    fputs(radka, stdout);
  }
  else {
    fputs(radka, fw);
  }
}

int main(void)
{
  if ((fw = fopen("vystup.txt", "w")) == NULL)
    return 1;

  kam = NIC;
  vypis("NIC - ahoj\n");

  kam = OBRAZOVKA;
  vypis("OBRAZOVKA - ahoj\n");

  kam = SOUBOR;
  vypis("SOUBOR - ahoj\n");

  if (fclose(fw) == EOF)
    printf("Chyba pri zavirani souboru\n");

  return 0;
}

