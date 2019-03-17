/*
 * cv05.c    v.2.0
 *
 * Konverze retezce pomoci funkce
 * ==============================
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX  81                 /* max. delka retezce */

void na_mala(char ss[]);
void na_velka(char ss[]);
void vymena(char ss[]);

int main(void)
{
  char s[MAX];

  printf("Zadej retezec ukonceny znakem 'U' nebo 'L' nebo 'X':\n");
  gets(s);

  switch (toupper(s[strlen(s) - 1])) {
    case 'L' :
      na_mala(s);
      break;

    case 'U' :
      na_velka(s);
      break;

    case 'X' :
      vymena(s);
      break;

    default:
      break;
  }

  /* ubrani ukoncujiciho znaku 'U' nebo 'L' nebo 'X' */
  s[strlen(s) - 1] = '\0';
  printf("Vysledny retezec je: %s\n", s);

  return 0;
}

void na_mala(char ss[])
{
  int i;

  for (i = strlen(ss) - 1;  i >= 0 ;  i--)
    ss[i] = tolower(ss[i]);
}

void na_velka(char ss[])
{
  int i, d;

  for (i = 0, d = strlen(ss);  i < d;  i++)
    ss[i] = toupper(ss[i]);
}

void vymena(char ss[])
{
  int i;

  for (i = 0;  i < strlen(ss);  i++) {
    if (isupper(ss[i]))
      ss[i] = tolower(ss[i]);
    else
      ss[i] = toupper(ss[i]);
  }
}

