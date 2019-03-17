/*
 * s309.c    v.2.0
 *
 * Docasna jmena souboru
 * =====================
 */

#include <stdio.h>

int main(void)
{
  char jmeno[256], *str;

  tmpnam(jmeno);
  printf("1.docasne jmeno: %s\n", jmeno);
  str = tmpnam(NULL);
  printf("2.docasne jmeno: %s\n", str);
  str = tmpnam(jmeno);
  printf("3.docasne jmeno: %s - %s\n", str, jmeno);
  return 0; 
}

