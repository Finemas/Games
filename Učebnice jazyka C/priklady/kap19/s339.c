/*
 * s339.c    v.2.0
 *
 * Prevody retezcu na cisla
 * ========================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *s, *chyba;
  long int l;

  s = "1234567";
  l = atol(s);
  printf("s=%s l=%ld\n", s, l);            // s=1234567 l=1234567

  s = "1234567";
  l = strtol(s, &chyba, 10);
  printf("s=%s l=%ld\n", s, l);            // s=1234567 l=1234567

  s = "FFFF";
  l = strtol(s, &chyba, 16);
  printf("s = %s  l = %ld\n", s, l);      // s = FFFF  l = 65535
  s = "0xFGFFF";
  l = strtol(s, &chyba, 16);
  printf("s = %s  l = %ld\n"              // s = 0xFGFFF  l = 15
   "chybny znak: %s\n", s, l, chyba);      // chybny znak: GFFF

s = "1111111111111111";
l = strtol(s, &chyba, 2);
printf("s=%s\n"                          // s=1111111111111111
       "l=%ld\n", s, l);                 // l=65535
  return 0;
}
