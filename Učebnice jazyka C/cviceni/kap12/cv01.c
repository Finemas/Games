/*
 * cv01.c    v.2.0
 *
 * Prace s retezcem
 * ================
 *
 */

#include <stdio.h>
#include <string.h>

#define DELKA_RADKY  80

/* uplny funkcni prototyp */
void ramecek(int pocet);

int main(void)
{
  char text[DELKA_RADKY];

  /* pomoci fgets() - posledni znak retezu je '\n' */
  printf("Zadej libovolny text: ");
  fgets(text, DELKA_RADKY, stdin);
  /* ubrani ukoncujiciho znaku '\n' */
  text[strlen(text) - 1] = '\0';
  ramecek(strlen(text));
  printf("* %s *", text);
  ramecek(strlen(text));

  /* pomoci gets() */
  printf("\nZadej text s mezerami: ");
  gets(text);
  ramecek(strlen(text));
  printf("* %s *", text);
  ramecek(strlen(text));

  /* pomoci scanf() */
  printf("\nZadej text bez mezer: ");
  scanf("%s", text);
  ramecek(strlen(text));
  printf("* %s *", text);
  ramecek(strlen(text));

  return 0;
}

/*
 * vypis ramecku
 */

void ramecek(int len)
{
  int i;

  putchar('\n');
  for (i = 1;  i <= len + 4;  i++)
    putchar('*');
  putchar('\n');
}

