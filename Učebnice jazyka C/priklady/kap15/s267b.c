/*
 * s267b.c    v.2.0
 *
 * Bitove pole - pouziti jako stavove slovo
 * ========================================
 */

#include <stdio.h>

typedef struct {
  unsigned zacatek : 3;   /* bity 0 - 2 */
  unsigned read    : 1;   /* bit 3 */
  unsigned write   : 1;   /* bit 4 */
  unsigned delete  : 1;   /* bit 5 */
} FLAGY;

FLAGY status;         /* globalni promenne jsou nulovany */

int main(void)
{
  printf("zacatek = %d, read = %d, write = %d, status = %d\n",
          status.zacatek, status.read, status.write, status.delete);

  /* nastaveni vsech na 1 */
  status.read = status.write = status.delete = 1;
  printf("zacatek = %d, read = %d, write = %d, status = %d\n",
          status.zacatek, status.read, status.write, status.delete);

  /* nastaveni vsech na 0 */
  status.read = status.write = status.delete = 0;
  printf("zacatek = %d, read = %d, write = %d, status = %d\n",
          status.zacatek, status.read, status.write, status.delete);

  /* test zda jsou WRITE a DELETE nulove */
  if (! (status.write | status.delete))
    printf("Jsou nulove\n");

  return 0;
}

