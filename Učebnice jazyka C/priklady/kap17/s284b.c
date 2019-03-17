/*
 * s284b.c    v.2.0
 *
 * Test chyby pomoci errno
 * =======================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;

  errno = 0;
  fp = fopen("NESMYSL.DAT", "r");
  if (fp == NULL) {
    fprintf(stderr, "Soubor neotevren\n");
    if (errno != 0)
      perror("Byla to chyba typu");
  }
  return 0;
}

