/*
 * dynam.c    v.2.0
 *
 * Ladeni dynamickych procesu
 * ==========================
 *
 * Pozor - uvedeno jen jako ukazka postupu
 *       - prelozitelne pouze pod Borland C prekladacem
 *       - pouzitelne pouze pro MS-DOS
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <dos.h>
#include <bios.h>

#define ESC  27

#define MAX  100

#define DOBA_REAKCE  0.9  /* vterin */
#define POCET_TIKU  DOBA_REAKCE * CLK_TCK

#define BUF(co)  {*p++ = co; if (p >= p_kon) p = p_zac;}

enum {
  VYPRSEL = 0, TIMER, KLAV,  NAHODA, PRECTENO, USPECH,
  NEPOUZIT = 0xFF
};

typedef enum {
  NE, ANO
} ANONE;
typedef void interrupt (*ISRPTR)(void);

ISRPTR  old_1c, old_09;
volatile ANONE povoleno;
volatile unsigned char cas;
unsigned char *p_zac, *p_kon, *p;
FILE *fw;

void zapis_buffer(void);        /* funkcni prototyp */

void interrupt int_1c(void)
{
  BUF(TIMER);
  if (cas >= POCET_TIKU) {
    povoleno = NE;
    BUF(VYPRSEL);
  }
  else {
    cas++;
    BUF(cas);
  }
  (*old_1c)();
}

void interrupt int_09(void)
{
  BUF(KLAV);
  (*old_09)();
}

int main(void)
{
  unsigned char c_nah, c_kla;

  atexit(zapis_buffer);        /* registrace funkce */

  old_1c = getvect(0x1C);
  setvect(0x1C, int_1c);

  old_09 = getvect(0x09);
  setvect(0x09, int_09);
  if ((p_zac = (unsigned char *) malloc(MAX)) == NULL) {
    fprintf(stderr, "Malo dynamicke pameti\n");
    exit(1);
  }

  p_kon = p_zac + MAX;
  for (p = p_zac;  p < p_kon;  p++)
    *p = NEPOUZIT;

  p = p_zac;

  srand(1);
  _setcursortype(_NOCURSOR);

  while (1) {
    clrscr();
    gotoxy(rand() % 80 + 1, rand() % 24 + 1);
    c_nah = rand() % 26 + 'a';
    putch(c_nah);
    BUF(NAHODA);
    BUF(c_nah);
    povoleno = ANO;
    cas = 0;

    while (povoleno == ANO) {
      if (bioskey(1) != 0) {    /* kbhit() je pomaly */
        c_kla = getch();
        BUF(PRECTENO);
        BUF(c_kla);

        if (c_kla == ESC)
          goto konec;

        if (c_nah == c_kla) {
          BUF(USPECH);
          sound(440); delay(500); nosound();
          break;
        }
      }
    }
  }
konec:
  setvect(0x1C, old_1c);
  setvect(0x09, old_09);

  return 0;
}



int zapis(unsigned char *p_p)
{
   int kolik;

   switch (*p_p++) {
     case TIMER :
       fprintf(fw, "int 1C - ");
       if (*p_p == VYPRSEL)
         fprintf(fw, "vyprsel cas - neuspesny pokus\n");
       else
         fprintf(fw, "%2u [tiku]\n", *p_p);
       kolik = 2;
       break;

     case KLAV :
       fprintf(fw, "INT 09\n");
       kolik = 1;
       break;

     case NAHODA :
       fprintf(fw, "Nahodny znak  '%c'\n", *p_p);
       kolik = 2;
       break;

     case PRECTENO :
       fprintf(fw, "Precteny znak '%c'\n", *p_p);
       kolik = 2;
       break;

     case USPECH :
       fprintf(fw, "  *** Uspesny pokus ***\n");
       kolik = 1;
       break;

     default :
       fprintf(fw, "Chybna synchronizace zacatku bufferu\n");
       kolik = 1;
       break;
   }
   return kolik;
}


void zapis_buffer(void)
{
  unsigned char *p_pom;
  struct date d;
  struct time t;

  if ((fw = fopen("HISTORY.TXT", "w")) == NULL) {
    fprintf(stderr, "Soubor nelze otevrit\n");
    exit(1);
  }

  getdate(&d);
  gettime(&t);

  fprintf(fw, "Ladici vypis vytvoren: %2d.%2d.%4d - %2d:%02d\n",
          d.da_day, d.da_mon, d.da_year, t.ti_hour, t.ti_min);
  fprintf(fw, "=========================================\n\n");

  if (*p != NEPOUZIT) {
    /* buffer se otocil alespon jednou */
    for (p_pom = p;  p_pom < p_kon; )
      p_pom += zapis(p_pom);
  }

  for (p_pom = p_zac;  p_pom < p; )
    p_pom += zapis(p_pom);

  if (fclose(fw) == EOF)
    fprintf(stderr, "Soubor nelze uzavrit\n");
}
