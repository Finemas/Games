/*
 * s250a.c    v.2.0
 *
 * Staticky definovane pole struktur
 * =================================
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
  TYP sa[MAX];
   
  for (i = 0;  i < MAX;  i++) {
    sa[i].k = i;
    sa[i].c = 'A' + i;
  }
  printf("%s[%d].k = %d, .c = %c\n", "sa", DVA, sa[DVA].k, sa[DVA].c);
  p_tmp = &sa[DVA];        /* totez  p_tmp = sa + DVA; */
  printf("%s[%d].k = %d, .c = %c\n", "sa", DVA, p_tmp->k, p_tmp->c);

  printf("%s[%d].k = %d, .c = %c\n", "sa", DVA, (sa + DVA)->k,
                                                 (*(sa + DVA)).c);
  return 0;
}

