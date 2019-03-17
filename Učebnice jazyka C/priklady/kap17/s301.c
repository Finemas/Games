/*
 * s301.c    v.2.0
 *
 * Primy pristup do binarniho souboru
 * ==================================
 */

#include <stdio.h>

int main(void)
{
  FILE *f;                       /* pro cteni i pro zapis */
  int i = 10;
  double d = 3.14159;
  f = fopen("POKUS.DAT", "wb+");
  fwrite(&i, sizeof(i), 1, f);   /* zapis dat do souboru */
  fwrite(&d, sizeof(d), 1, f);
  fflush(f);                     /* vyprazdneni bufferu */

  printf("Pozice v souboru je %ld\n", ftell(f));

  fseek(f, -ftell(f), SEEK_CUR); /* posun na zac. souboru */
  fseek(f, 0L, SEEK_SET);        /* posun na zac. souboru */
  fseek(f, (long) 0, SEEK_SET);  /* posun na zac. souboru */

  i = 0; d = 0.0;                /* nulovani promennych */
  fread(&i, sizeof(i), 1, f);    /* cteni a zobrazeni dat */
  fread(&d, sizeof(d), 1, f);
  printf("Nactena data: i = %d, d = %f\n", i, d);
  fclose(f);
  return 0;
}

