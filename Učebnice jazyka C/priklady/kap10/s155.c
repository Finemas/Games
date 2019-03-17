/*
 * s155.c    v.2.0
 *
 * void jako formalni parametr funkce
 * ==================================
 */

#include <stdio.h>

void vymen_pointery(void **p_x, void **p_y)
{
  void *p_pom;

  p_pom = *p_x;
  *p_x = *p_y;
  *p_y = p_pom;
}

int main(void)
{
  char c = 1, *p_c = &c, d = 2, *p_d = &d;
  FILE *fin = stdout,   /* zamerna chyba */
       *fout = stdin;

  fprintf(fin, "c = %d, d = %d\n", *p_c, *p_d);
  vymen_pointery((void *)&p_c, (void *)&p_d);
  vymen_pointery(&fin, &fout);
  fprintf(fout, "c = %d, d = %d\n", *p_c, *p_d);
  return 0;
}

