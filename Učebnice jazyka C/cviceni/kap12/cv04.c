/*
 * cv04.c    v.2.0
 *
 * Tvoreni slov, ktera se daji stejne cist i pozpatku
 * ==================================================
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX  81             /* max. delka retezce */

int main(void)
{
  char s[MAX];
  int i;

  printf("Zadej prvni polovinu slova: ");
  scanf("%s", s);

  /* prvni polovina slova */
  printf("Nove slovo je:              %s", s);
  
  /* druha polovina slova */
  for (i = strlen(s) - 2;  i >= 0;  i--)
    putchar(s[i]);

  putchar('\n');

  return 0;
}

