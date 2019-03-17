/*
 * cv02.c    v.2.0
 *
 * Pouziti pointeru na funkci pro volani funkce
 * ============================================
 *
 */

#include <stdio.h>

/* definice pristupoveho pointeru */
typedef int (* P_FCE)(void);    /* definice pointeru na funkci bez parametru
                                   vracejici typ int */

int ahoj(void)
{
  static int kolikrat = 0;

  printf("%2d ahoj ", ++kolikrat);
  return kolikrat;
}

int main(void)
{
  P_FCE p_ahoj;

  p_ahoj = ahoj;

  while (p_ahoj() < 20)
    ;

  putchar('\n');                /* odradkovani */
  return 0;
}
