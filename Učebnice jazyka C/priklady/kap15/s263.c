/*
 * s263.c    v.2.0
 *
 * Prevody znaku pomoci bitovych operaci
 * =====================================
 */

#include <stdio.h>

#define na_velka(c) (c & 0xDF)  /* 0xDF je 1101 1111 binarne */
#define na_mala(c)  (c | 0x20)  /* 0x20 je 0010 0000 binarne */

int main(void)
{
  printf("%c na mala  = %c\n", 'A', na_mala('A'));
  printf("%c na velka = %c\n", 'a', na_velka('a'));
  return 0;
}
