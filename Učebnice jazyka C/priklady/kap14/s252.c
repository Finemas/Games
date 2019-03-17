/*
 * s252.c    v.2.0
 *
 * Pointer na pointer na strukturu
 * ===============================
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

  TYP **p_sd;

  p_sd = (TYP **) malloc(MAX * sizeof(TYP *));
  if (p_sd == NULL) {
    printf("Malo pameti\n");
    return 1;
  }

  /* od ted je to jako pole p_sc */
  for (i = 0;  i < MAX;  i++) {
    p_sd[i] = (TYP *) malloc(sizeof(TYP));
    if (p_sd[i] == NULL) {
      printf("Malo pameti\n");
      return 1;
    }
    p_sd[i]->k = i;
    p_sd[i]->c = 'A' + i;
  }

  printf("%s[%d].k = %d, .c = %c\n", "p_sd", DVA, p_sd[DVA]->k, 
                                      p_sd[DVA]->c);
  p_tmp = p_sd[DVA];        /* totez  p_tmp = *(p_sd + DVA); */
  printf("%s[%d].k = %d, .c = %c\n", "p_sd", DVA, p_tmp->k, 
                    p_tmp->c);

  printf("%s[%d].k = %d, .c = %c\n", "p_sd", DVA, 
                 (*(p_sd + DVA))->k,  (*(*(p_sd + DVA))).c);


  for (i = 0;  i < MAX;  i++) {
    free((void *) p_sd[i]);
  }
  free((void *) p_sd);

  return 0;
}

