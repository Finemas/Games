/*
 * s235.c    v.2.0
 *
 * Pristup k prvkum struktury pomoci pointeru na strukturu
 * =======================================================
 *
 * Alokace dynamicke struktury
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char jmeno[30];
  int  rocnik;
} STUDENT;

int main(void)
{
  STUDENT s, *p_s;

  if ((p_s = (STUDENT *) malloc(sizeof(STUDENT))) == NULL) {
    printf("Malo pameti\n");
    return 1;
  }

  s.rocnik = 3;
  printf("Rocnik je %d\n", s.rocnik);

  (*p_s).rocnik = 4;
  printf("Rocnik je %d\n", (*p_s).rocnik);

  p_s->rocnik = 5;
  printf("Rocnik je %d\n", p_s->rocnik);

  free((void *) p_s);
  return 0;
}

