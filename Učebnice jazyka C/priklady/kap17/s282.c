/*
 * s282.c    v.2.0
 *
 * Uzavirani standardnich vstupu a vystupu
 * =======================================
 */

#include <stdio.h>

int main(void)
{
  FILE *fw;

  printf("printf()  - pred uzavrenim\n");
  fprintf(stdout, "fprintf() - pred uzavrenim\n");

  printf("Po stisku <Enter> bude vystup uzavren: ");
  while (getchar() != '\n')
    ;

  fclose(stdout);                  /* prvni zavreni */
  if (fclose(stdout) == EOF) {     /* pokus o druhe zavreni */
    fprintf(stderr, "chyba pri zavirani stdout\n");
  }

  if (fclose(stdin) == EOF) {
    fprintf(stderr, "chyba pri zavirani stdin\n");
    return 1;
  }

  printf("printf()  - PO uzavreni\n");
  fprintf(stdout, "fprintf() - PO uzavreni\n");

  fprintf(stderr, "Na dalsi stisk <Enter> uz program neceka");
  (void) getchar();

  return 0;
}
