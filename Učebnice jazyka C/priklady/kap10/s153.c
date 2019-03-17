/*
 * s153.c    v.2.0
 *
 * Cteni radky z klavesnice
 * ========================
 */

#include <stdio.h>

int cti_radku(int *p_mezery, int *p_male)
{
  int c, pocet = 0;

  *p_mezery = 0;
  *p_male = 0;

  while ((c = getchar()) != '\n') {
    pocet++;
    if (c == ' ')
      (*p_mezery)++;           /* zavorky nutne !!! */
    else if (c >= 'a'  &&  c <= 'z')
      (*p_male)++;             /* zavorky nutne !!! */
  }
  return ((pocet == 0) ? 0 : 1);
}

int main(void)
{
  int mezery, male;

  while (cti_radku(&mezery, &male) == 1) {
    printf("Na radce bylo %d mezer a %d malych pismen.\n",
           mezery, male);
  }
  return 0;
}

