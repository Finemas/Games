/*
 * cv05.c    v.2.0
 *
 * Formatovany zapis cisel do souboru
 * ==================================
 *
 */

#include <stdio.h>

int main(void)
{
  FILE *fr;
  int i;

  if ((fr = fopen("CISLA.TXT", "w")) == NULL)  {
    printf("Soubor CISLA.TXT se nepodarilo otevrit\n");
    return 1;
  }

  for (i = 1;  i <= 20;  i++)
    fprintf(fr, "  $%.2f\n", i * 3.14);

  if (fclose(fr) == EOF)
    printf("Soubor CISLA.TXT se nepodarilo uzavrit\n");

  return 0;
}

