/*
 * s197.c    v.2.0
 *
 * Cteni komplikovanym formatem
 * ============================
 */

#include <stdio.h>

int main(void)
{
  long int suma = 0;
  FILE *fr;
  int kolik;
  char akce[2];

  if ((fr = fopen("PENIZE.TXT", "r")) == NULL) {
    printf("Soubor PENIZE.TXT nelze otevrit\n");
    return;
  }

  while (fscanf(fr, "%1s", akce) != EOF) {
    fscanf(fr, " $%d", &kolik);
/*    printf("%d\n", kolik); */
    suma += (akce[0] == '+') ? kolik : (-1 * kolik);
  }

  printf("Celkem: $%ld\n", suma);

  if (fclose(fr) == EOF)
    printf("Soubor PENIZE.TXT se nepodarilo uzavrit.\n");
  return 0;
}

