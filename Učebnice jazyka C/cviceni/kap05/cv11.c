/*
 * cv11.c    v.2.0
 *
 * Cteni z klavesnice pomoci while a pocitani malych a velkych pismen
 * ==================================================================
 *
 */

#include <stdio.h>

int main(void)
{
  int c,                        /* znaky se ctou do int !!! */
      mala = 0,                 /* citac pro mala pismena */
      velka = 0;                /* citac pro velka pismena */

  printf("Zadavej znaky a zadavani ukonci <Enter>\n");

  while ((c = getchar()) != '\n') {
    if (c >= 'A'  &&  c <= 'Z')
      velka++;
    if (c >= 'a'  &&  c <= 'z')
      mala++;
  }

  printf("\nBylo precteno:\n %d malych pismen\n %d velkych pismen\n",
         mala, velka);
  return 0;
}

