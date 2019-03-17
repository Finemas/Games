/*
 * cv02.c    v.2.0
 *
 * Adresy radek a sloupcu dvourozmerneho pole
 * ==========================================
 *
 */

#include <stdio.h>

#define MAX   4

int a[MAX + 1][MAX + 1];

int main(void)
{
  printf("Adresa zacatku pole   : %ph\n", a);
  printf("Adresa 0-te radky     : %ph\n", a[0]);
  printf("Adresa 1-ni radky     : %ph\n", a[1]);
  printf("Adresa prvku a[0][0]  : %ph\n", &a[0][0]);
  printf("Adresa prvku a[1][0]  : %ph\n", &a[1][0]);
  printf("Adresa prvku a[%1d][%1d]  : %ph\n", MAX, MAX, &a[MAX][MAX]);
  printf("Velikost pole a[][]   : %Xh\n", sizeof(a));

  return 0;
}

