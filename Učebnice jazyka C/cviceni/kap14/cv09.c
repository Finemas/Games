/*
 * cv09.c    v.2.0
 *
 * Vypis polozek vyctoveho typu
 * ============================
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
  FORD, TOYOTA, RENAULT, SKODA, FIAT
} AUTOMOBILY;

char *jmena_aut[] = { "Ford", "Toyota", "Renault", "Skoda", "Fiat" };

int main(void)
{
  int i, j;

  printf("Kupte si auta:\n");
  for (i = FORD;  i <= FIAT;  i++) {
    printf("%d. ", i);
    for (j = 0;  j < strlen(jmena_aut[i]);  j++) {
      putchar(jmena_aut[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');

  printf("Asi si nekoupim ani jedno z techto aut:\n");
  for (i = FIAT;  i >= FORD;  i--) {
    printf("%d. %s\n", i, jmena_aut[i]);
  }
  putchar('\n');

  printf("Libi se vam tato auta?\n");
  for (i = FORD;  i <= FIAT;  i++) {
    printf("%d. ", i);
    puts(jmena_aut[i]);
  }
  putchar('\n');

  return 0;
}

