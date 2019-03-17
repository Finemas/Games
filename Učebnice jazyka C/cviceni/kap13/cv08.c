/*
 * cv08.c    v.2.0
 *
 * Parametry vstupni radky opsane velkymi pismeny
 * ==============================================
 */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int  i;

  printf("Vstupni radka ma %d parametru\n", argc);
  for (i = 0;  i < argc;  i++) {
    printf("%2d: ", i + 1);
    while (*(argv[i]) != '\0')
      putchar(toupper(*(argv[i])++));
    putchar('\n');
  }

  return 0;
}

