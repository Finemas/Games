/*
 * cv11.c    v.2.0
 *
 * Zjisteni rozsahu typu short a long
 * ==================================
 *
 */

#include <stdio.h>

int main(void)
{
  short int ssi = -1;
  long int sli = -1;
  unsigned short int usi;
  unsigned long int uli;

  usi = (unsigned short int) ssi;
  printf("Rozsah typu 'unsigned short int': 0 .. %u\n", usi);
  printf("Rozsah typu 'signed short int': %d .. %d\n",
          usi / 2 + 1, usi / 2);

  uli = (unsigned long int) sli;
  printf("Rozsah typu 'unsigned long int': 0 .. %lu\n", uli);
  printf("Rozsah typu 'signed long int': %ld .. %ld\n",
          uli / 2 + 1, uli / 2);
  return 0;
}

