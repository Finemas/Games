/*
 * cv11.c    v.2.0
 *
 * Tisk retezce po slovech
 * =======================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  100             /* max. delka retezce */

int main(void)
{
  char radka[MAX];
  char *p_z, *p_k;              /* zacatek a konec slova */

  printf("Zadej nekolik slov oddelenych mezerou:\n");
  fgets(radka, MAX, stdin);

  p_z = radka;
  while ((p_k = strchr(p_z, ' ')) != NULL) {
    *p_k = '\0';                /* ukonceni slova */
    puts(p_z);
    p_z = p_k + 1;
  }
  puts(p_z);                    /* tisk posledniho slova */

  return 0;
}

