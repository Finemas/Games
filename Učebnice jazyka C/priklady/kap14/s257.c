/*
 * s250.c    v.2.0
 *
 * Prakticke vyuziti unionu
 * ========================
 */

#include <stdio.h>
#include <ctype.h>

#define POCET    10
/* vyprazdneni bufferu klavesnice
   - ukoncujici strednik se doda pri volani */
#define cisti()   while (getchar() != '\n')

typedef enum {
 CISLO = 'I',
 ZNAK  = 'C'
} TYP;

typedef union {
  char c;
  int  i;
} CHARINT;

typedef struct {
  CHARINT hodnota;
  TYP     typ;
} PRVEK;

PRVEK pole[POCET];

int main(void)
{
  int i, c;

  for (i = 0;  i < POCET;  i++) {
    printf("%d. polozka:\ntyp: ", i + 1);
    c = toupper(getchar());
    cisti();
    switch (c) {
      case CISLO :
        pole[i].typ = CISLO;
        printf("cislo: ");
        scanf("%d", &pole[i].hodnota.i);
        break;

      case ZNAK :
        pole[i].typ = ZNAK;
        printf("znak: ");
        scanf("%c", &pole[i].hodnota.c);
        break;

      default :
        printf("Neznamy typ\n");
        break;
    }
    cisti();
  }

  /* tisk nactenych hodnot */
  for (i = 0;  i < POCET;  i++) {
    if (pole[i].typ == CISLO)
      printf("%d. polozka = %d\n", i + 1, pole[i].hodnota.i);
    else
      printf("%d. polozka = %c\n", i + 1, pole[i].hodnota.c);
  }
  return 0;
}

