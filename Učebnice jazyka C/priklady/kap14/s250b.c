/*
 * s250b.c    v.2.0
 *
 * Dynamicky definovane pole struktur
 * ==================================
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

  TYP *p_sb;
 
  p_sb = (TYP *) malloc(MAX * sizeof(TYP));
  if (p_sb == NULL) {
    printf("Malo pameti\n");
    return 1;
  }

  /* od ted je to jako pole sa */
  for (i = 0;  i < MAX;  i++) {
    p_sb[i].k = i;
    p_sb[i].c = 'A' + i;
  }
  
  printf("%s[%d].k = %d, .c = %c\n", "p_sb", DVA, p_sb[DVA].k, 
                                                    p_sb[DVA].c);
  p_tmp = &p_sb[DVA];         /* totez  p_tmp = p_sb + DVA; */
  printf("%s[%d].k = %d, .c = %c\n", "p_sb", DVA, p_tmp->k, 
                                                    p_tmp->c);

  printf("%s[%d].k = %d, .c = %c\n", "p_sb", DVA, (p_sb + DVA)->k,
                                                    (*(p_sb + DVA)).c);
  free((void *) p_sb);
  return 0;
}

