/*
 * cv03.c    v.2.0
 *
 * Serazeni znaku v retezci podle abecedy
 * ======================================
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX    20
#define ZAC    ' ' + 1                 /* zacatecni znak ASCII tabulky */
#define KON    'z'                     /* koncovy znak */

int main(void)
{
  char s[MAX];
  int i, j;

  printf("Zadej retezec: ");
  scanf("%s", s);

  for (j = ZAC;  j <= KON;  j++) {
    for (i = 0;  i < strlen(s);  i++) {
      if (s[i] == j) {
        putchar(s[i]);
      }
    }
  }

  return 0;
}

