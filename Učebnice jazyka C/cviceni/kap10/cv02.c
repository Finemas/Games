/*
 * cv02.c    v.2.0
 *
 * Prevod pismen pomoci funkce se vstupnimi a vystupnimi parametry
 * ===============================================================
 *
 *
 */

#include <stdio.h>
#include <ctype.h>

/* uplny funkcni prototyp */
int set(char vstup, char *p_vystup);

int main(void)
{
  char c_in, c_out;

  printf("Zadavej jednotlive libovolne znaky ('*' = konec): ");
  do {
    c_in = getchar();           /* precteni znaku */
    /* vycisteni bufferu */
    while (getchar() != '\n')
      ;

    if (set(c_in, &c_out) == 1)
      printf("Znak '%c' byl preveden na '%c'\n", c_in, c_out);
    else
      printf("Znak '%c' byl ponechan ('%c')\n", c_in, c_out);
  } while(c_in != '*');

  return 0;
}


/*
 * funkce zjisti, zda je v prvnim parametru pismeno a pak:
 *   i) vraci hodnotu 1
 *  ii) v druhem parametru vraci opacny typ pismene
 *
 * neni-li v prvnim parametru pismeno, pak:
 *    i) vraci 0
 *   ii) v druhem parametru vraci tentyz znak
 */

int set(char vstup, char *p_vystup)
{
  if (isalpha(vstup) != 0) {
    /* je to pismeno */
    *p_vystup = (islower(vstup) != 0) ? toupper(vstup) : tolower(vstup);
    return 1;
  }
  else {
    *p_vystup = vstup;
    return 0;
  }
}

