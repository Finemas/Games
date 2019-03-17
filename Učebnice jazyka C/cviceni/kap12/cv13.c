/*
 * cv13.c    v.2.0
 *
 * Funkce pro vymazani casti retezce
 * =================================
 *
 */

#include <stdio.h>
#include <string.h>

/* uplny funkcni prototyp */
void strdel(char *s, int i, int n);

int main(void)
{
  char str[80] = "Dolevali bychom usilovne pitnou vodu.";
/*                0123456789012345678901234567890123456
*/

  puts(str);
  strdel(str, 34, 2);
  strdel(str, 27, 5);
  strdel(str, 19, 5);
  strdel(str, 16, 1);
  strdel(str, 13, 2);
  strdel(str,  7, 1);
  strdel(str,  1, 4);
  puts(str);

  return 0;
}

void strdel(char *s, int i, int n)
{
  strcpy(&s[i], &s[i + n]);
}

