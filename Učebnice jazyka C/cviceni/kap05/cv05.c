/*
 * cv05.c    v.2.0
 *
 * Chybna priorita v nacitani a v porovnavani
 * ==========================================
 *
 */

#include <stdio.h>

int main(void)
{
  int c;

  /* spravna priorita */
  printf("Zadej velke pismeno (A az Z): ");
  if ((c = getchar()) >= 'A'  &&  c <= 'Z') {
    printf("Spravna priorita operatoru:\n");
    printf("Bylo zadano pismeno s ASCII hodnotou: %d\n", c);
  }

  /* vyprazdneni bufferu klavesnice */
  while (getchar() != '\n')
    ;

  /* chybna priorita */
  printf("Zadej velke pismeno (A az Z): ");
  if (c = getchar() >= 'A'  &&  c <= 'Z') {
    printf("Chybna priorita operatoru:\n");
    printf("Bylo zadano pismeno s ASCII hodnotou: %d\n", c);
  }
  return 0;
}

