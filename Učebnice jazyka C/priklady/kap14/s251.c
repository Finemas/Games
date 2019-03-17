/*
 * s251.c    v.2.0
 *
 * Pole deseti pointeru na stuktury
 * ================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX  10
#define DVA  2

typedef struct {
  int  k;
  char c;
} TYP;

int main(void)
{
  int i;
  TYP *p_tmp;

  TYP *p_sc[MAX];

  for (i = 0;  i < MAX;  i++) {
    p_sc[i] = (TYP *) malloc(sizeof(TYP));
    if (p_sc[i] == NULL) {
      printf("Malo pameti\n");
      return 1;
    }
    p_sc[i]->k = i;
    p_sc[i]->c = 'A' + i;
  }

  printf("%s[%d].k = %d, .c = %c\n", "p_sc", DVA, p_sc[DVA]->k, p_sc[DVA]->c);
  p_tmp = p_sc[DVA];       /* totez  p_tmp = *(p_sc + DVA); */
  printf("%s[%d].k = %d, .c = %c\n", "p_sc", DVA, p_tmp->k, p_tmp->c);

  printf("%s[%d].k = %d, .c = %c\n", "p_sc", DVA, (*(p_sc + DVA))->k,
                                                 (*(*(p_sc + DVA))).c);

  for (i = 0;  i < MAX;  i++) {
    free((void *) p_sc[i]);
  }
  return 0;
}

