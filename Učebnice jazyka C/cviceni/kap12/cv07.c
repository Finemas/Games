/*
 * cv07.c    v.2.0
 *
 * Hledani znaku v retezci
 * =======================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  81             /* max. delka retezce */

int main(void)
{
  char str[MAX];
  char *p_c;
  int  c, i, j, k;

  printf("Zadej libovolny retezec:\n");
  gets(str);
  printf("Zadej hledany znak: ");
  c = getchar();

  /* vypis zadaneho retezce */
  puts(str);

  /* prace jen s casti retezce */
  i = 0;
  while ((p_c = strchr(&str[i], c)) != NULL) {
    k = p_c - str;              /* index z adresy */
    /* tisk mezer */
    for (j = 0;  j < k - i;  j++)
      putchar(' ');
    putchar('*');               /* podtrzeni */
    i = k + 1;                  /* posun na nasledujici znak */
  }
  putchar('\n');

  /* totez mnohem jednoduseji */
  for (i = 0;  i < strlen(str);  i++) {
    if (str[i] == c)
      putchar('*');
    else
      putchar(' ');
  }
  putchar('\n');

  return 0;
}

