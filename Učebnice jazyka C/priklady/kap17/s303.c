/*
 * s303.c    v.2.0
 *
 * Pole struktur na disku - chybna verze
 * =====================================
 */

#include <stdio.h>
#include <stdlib.h>

#define POCET  10

typedef struct {
  int poradi;
  int hodnota;
} ZAZNAM;


int main(void)
{
  int     i;
  FILE   *f;
  ZAZNAM  z;

  if ((f = fopen("DATA.BIN", "wb+")) == NULL) {
    printf("Nelze otevrit soubor\n");
    exit(1);
  }

  /* nahodna inicializace */
  for (i = 1;  i <= POCET;  i++) {
    z.poradi = i;
    z.hodnota = rand() % 100;
    if (fwrite((void *)&z, sizeof(ZAZNAM), 1, f) != 1)
      printf("Chyba zapisu %d. polozky\n", i);
  }

  if (fflush(f) == EOF)
    printf("Chyba pri zapisu bufferu\n");
  if (fseek(f, 0L, SEEK_SET) != 0)
    printf("Chyba pri presunu na zacatek souboru\n");

  
  errno = 0;
  /* cteni polozek souboru a jejich oprava */
  while (fread((void *)&z, sizeof(ZAZNAM), 1, f) == 1) {
    printf("%2d. %2d ", z.poradi, z.hodnota);

    if (z.hodnota < 50) {        /* oprava polozky */
      z.hodnota += 50;
      printf(" -> %2d", z.hodnota);

      /* navrat na zacatek polozky */
      fseek(f, -(long) sizeof(ZAZNAM), SEEK_CUR);

      /* zapis opravene polozky */
      if (fwrite((void *)&z, sizeof(ZAZNAM), 1, f) != 1) {
        printf("Chyba zapisu %d. polozky\n", i);
      }
    }
    putchar('\n');
  }

  if (errno != 0)      /* skoncilo cteni chybou? */
    perror("");

  if (fflush(f) == EOF)
    printf("Chyba pri zapisu bufferu\n");
  if (fseek(f, 0L, SEEK_SET) != 0)
    printf("Chyba pri presunu na zacatek souboru\n");

  printf("\nNove hodnoty\n");

  errno = 0;
  /* vypis opraveneho souboru */
  while(fread((void *)&z, sizeof(ZAZNAM), 1, f) == 1)
    printf("%d:%2d  ", z.poradi, z.hodnota);

  if (errno != 0)      /* skoncilo cteni chybou? */
    perror("");

  if (fclose(f) == EOF)
    printf("Soubor nelze uzavrit\n");

  return 0;
}

