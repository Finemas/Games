/*
 * s92b.c    v.2.0
 *
 * Vyraz jako symbolicka konstanta
 * ===============================
 */

#include <stdio.h>

#define POSUN        ('a' - 'A')
#define KONEC_RADKY  '\n'
#define PRED_MALE    '#'

int main()
{
  int c;

  while ((c = getchar()) != KONEC_RADKY) {
    if (c >= 'a'  &&  c <= 'z') {
      putchar(PRED_MALE);
      putchar(c - POSUN);
    }
    else
      putchar(c);
  }
  return 0;
}

