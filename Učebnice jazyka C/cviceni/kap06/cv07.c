/*
 * cv07.c    v.2.0
 *
 * Porovnani dvou souboru
 * ======================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr1, *fr2;
  long rozdily = 0;             /* pocet rozdilnych znaku v souborech */

  if ((fr1 = fopen("PISMENA1.TXT", "r")) == NULL) {
    printf("Soubor PISMENA1.TXT se nepodarilo otevrit\n");
    return 1;
  }
  if ((fr2 = fopen("PISMENA2.TXT", "r")) == NULL) {
    printf("Soubor PISMENA2.TXT se nepodarilo otevrit\n");
    return 1;
  }

  /* test konce obou souboru pomoci feof() je zde vyhodne */
  while (feof(fr1) == 0  ||  feof(fr2) == 0) {
    if (getc(fr1) != getc(fr2)) {
      rozdily++;
    }
  }

  if (rozdily == 0)
    printf("Soubory jsou shodne\n");
  else
    printf("Soubory se lisi v %ld znacich\n", rozdily);

  if (fclose(fr1) == EOF)
    printf("Soubor PISMENA1.TXT se nepodarilo uzavrit\n");
  if (fclose(fr2) == EOF)
    printf("Soubor PISMENA2.TXT se nepodarilo uzavrit\n");

  return 0;
}

