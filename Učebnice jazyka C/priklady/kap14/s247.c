/*
 * s247.c    v.2.0
 *
 * Dynamicke struktury - ruzne zpusoby alokace
 * ===========================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char jmeno[30];
  int  rocnik;
} STUDENT;

STUDENT *vytvor1(void)
{
  STUDENT *p_pom;

  p_pom = (STUDENT *) malloc(sizeof(STUDENT));
  if (p_pom == NULL)
    printf("Malo pameti\n");
  return p_pom;
}

void vytvor2(STUDENT **p_s)
{
  *p_s = (STUDENT *) malloc(sizeof(STUDENT));
  if (*p_s == NULL)
    printf("Malo pameti\n");
}

void nastav(STUDENT *p_s, char *jmn, int rok)
{
  p_s->rocnik = rok;
  strcpy(p_s->jmeno, jmn);
}

int main(void)
{
  STUDENT s, *p_s1, *p_s2;

  p_s1 = vytvor1();                /* pouziti vytvor1() */
  vytvor2(&p_s2);                  /* pouziti vytvor2() */

  /* prace s polozkami struktur */
  s.rocnik = 3;
  p_s1->rocnik = s.rocnik + 1;
  p_s2->rocnik = 5;
  nastav(&s, "pavel", 1);
  nastav(p_s1, "karel", 2);
  nastav(p_s2, "honza", 3);

  printf("Jmeno: %s, rocnik: %d\n", s.jmeno, s.rocnik);
  printf("Jmeno: %s, rocnik: %d\n", p_s1->jmeno, p_s1->rocnik);
  printf("Jmeno: %s, rocnik: %d\n", p_s2->jmeno, p_s2->rocnik);
  return 0;
}

