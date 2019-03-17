/*
 * s207b.c    v.2.0
 *
 * Typicke pouziti funkce fgets()
 * ==============================
 */

#include <stdio.h>
#include <string.h>

#define MAX            1000
#define JMENO_SOUBORU  "dopis.txt"

int main(void)
{
  FILE *fr;
  char str[MAX];
  int i, delka;

  if ((fr = fopen(JMENO_SOUBORU, "r")) == NULL) {
    printf("%s neotevren\n", JMENO_SOUBORU);
    return 1;
  }

  while (fgets(str, MAX, fr) != NULL) {
    delka = strlen(str);
    if (delka == MAX - 1  &&  str[delka - 1] != '\n') {
      printf("Chyba - vstupni radka prilis dlouha\n"
             "%s\n", str);
      return 1;
    }

    if (str[delka - 1] == '\n')
      str[delka - 1] = '\0';   /* odstraneni '\n' */

    /* dalsi zpracovani, napr. tisk */
    printf("%s\n", str);
  }

  if (fclose(fr) == EOF)
    printf("%s nezavren\n", JMENO_SOUBORU);

  return 0;
}

