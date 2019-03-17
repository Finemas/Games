/*
 * cv01.c    v.2.0
 *
 * Adresy prvku struktury a unionu
 * ===============================
 *
 */

#include <stdio.h>

typedef struct {
  float f;
  char  c;
  int   i;
} S_POKUS;

typedef union {
  float f;
  char  c;
  int   i;
} U_POKUS;

int main(void)
{
  S_POKUS  s;
  U_POKUS  u;

  printf("Adresa struktury 's'   : %p\n", &s);
  printf("Adresa prvku 's.f'     : %p\n", &s.f);
  printf("Adresa prvku 's.c'     : %p\n", &s.c);
  printf("Adresa prvku 's.i'     : %p\n", &s.i);
  printf("Velikost struktury 's' : %d [B]\n", sizeof(s));

  putchar('\n');

  printf("Adresa unionu 'u'      : %p\n", &u);
  printf("Adresa prvku 'u.f'     : %p\n", &u.f);
  printf("Adresa prvku 'u.c'     : %p\n", &u.c);
  printf("Adresa prvku 'u.i'     : %p\n", &u.i);
  printf("Velikost unionu 'u'    : %d [B]\n", sizeof(u));

  return 0;
}

