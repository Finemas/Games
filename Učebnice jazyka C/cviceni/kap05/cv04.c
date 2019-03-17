/*
 * cv04.c    v.2.0
 *
 * Konverze hexadecimalniho cisla
 * ==============================
 *
 */

#include <stdio.h>

int main(void)
{
  int c1, c2, i;

  printf("Zadejte hexadecimalni cislo (00 az FF): ");
  c1 = getchar();
  c2 = getchar();

  if (c1 >= '0'  &&  c1 <= '9')
    i = 16 * (c1 - '0');
  else
    /* predpokladame, ze je cislo zadane velkymi pismeny
       a ze je v povolenem rozsahu */
    i = 16 * (c1 - 'A' + 0xA);

  if (c2 >= '0'  &&  c2 <= '9')
    i += c2 - '0';
  else
    i += c2 - 'A' + 0xA;

  printf("Dekadicka hodnota je: %d\n", i);
  return 0;
}

