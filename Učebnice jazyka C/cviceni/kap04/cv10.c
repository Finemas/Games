/*
 * cv10.c    v.2.0
 *
 * Zjisteni rozsahu typu int
 * =========================
 *
 */

#include <stdio.h>

int main(void)
{
  int si = -1;
  unsigned int ui;

  ui = (unsigned int) si;
  printf("Rozsah typu 'unsigned int': 0 .. %u\n", ui);
  printf("Rozsah typu 'signed int': %d .. %d\n", ui / 2 + 1, ui / 2);
  return 0;
}

