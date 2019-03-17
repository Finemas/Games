/*
 * cv02.c    v.2.0
 *
 * Vyuziti maker z ctype.h
 * =======================
 *
 */

#include <stdio.h>
#include <ctype.h>

#define EOLN  '\n'

int main(void)
{
  int c,
      cislice = 0;

  printf("Zadej nejake znaky:\n");
  while ((c = getchar()) != EOLN) {
    if (isdigit(c))
      cislice++;
    if (isalpha(c))
      putchar(toupper(c));
  }

  printf("\nNa vstupni radce bylo %d cislic\n", cislice);
  return 0;
}

