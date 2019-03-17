/*
 * s307.c    v.2.0
 *
 * Presmerovani stderr do souboru
 * ==============================
 */

#include <stdio.h>

int main(void)
{
  FILE *f;

  /* presmerovani stderr do souboru */
  if ((f = freopen("CHYBY.TXT", "w", stderr)) == NULL)
    printf("Chyba v presmerovani stderr\n");

  printf("f = %p  stderr = %p\n", f, stderr);

  /* stderr a f jsou synonyma */
  fprintf(stderr, "1) Tato zprava se vypise do souboru.\n");
  fprintf(f, "2) Tato zprava se vypise do souboru.\n");

  if (fclose(stderr) == EOF)
    printf("Chyba v uzavreni stderr\n");

  if (fclose(f) == EOF)
    printf("Chyba v uzavreni f\n");

  return 0;
}

