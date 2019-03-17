/*
 * cv01.c    v.2.0
 *
 * Cyklus do-while a prepinac
 * ==========================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr;
  int c;

  if ((fr = fopen("ZNAKY.TXT", "r")) == NULL) {
    printf("Soubor se nepodarilo otevrit\n");
    return 1;
  }

  do {
    switch (c = getc(fr)) {
      case '0' :
        printf("Byla to nula\n");
        break;

      case '1' :
        printf("Byla to jednicka\n");
        break;

      default :
        break;
    }
  } while (c != 'q'  &&  c != EOF);

  if (fclose(fr) == EOF) {
    printf("Soubor se nepodarilo uzavrit\n");
    return 1;
  }

  return 0;
}

