/*
 * s280.c    v.2.0
 *
 * V rezimu "append" nelze zapisovat na zacatek souboru
 * ====================================================
 */

#include <stdio.h>

int main(void)
{
  FILE *fw;

  fw = fopen("POKUS.TXT", "w");
  fprintf(fw, "TOTO JE PRVNI TEST");
  fclose(fw);

  fw = fopen("POKUS.TXT", "a");
  fseek(fw, 0L, SEEK_SET);  /* nastaveni na zacatek souboru */
  printf("Pozice: %ld\n", ftell(fw));
  fprintf(fw, "toto je druhy test");
  fclose(fw);
  return 0;
}

