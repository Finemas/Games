/*
 * s344.c    v.2.0
 *
 * Razeni a vyhledavani pomoci knihovnich funkci
 * =============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX  20

/* funkcni prototypy */
int sort_vek(const void *p_a, const void *p_b);
int search_vek(const void *p_a, const void *p_b);
int sort_jmeno(const void *p_a, const void *p_b);
int search_jmeno(const void *p_a, const void *p_b);
void nahodna_inicializace(void);

typedef struct {
  int  vek;
  char jmeno[6];
} CLOVEK;

CLOVEK pole[MAX];

int main(void)
{
  int     i;
  char    jmn[6];
  int     stari;
  CLOVEK *p_clovek;

  nahodna_inicializace();
  printf("Serazeno podle veku\n");

  qsort((void *)pole, MAX, sizeof(CLOVEK), sort_vek);

  for (i = 0;  i < MAX;  i++) {
    printf("%2d: %3d - %s\n", i, pole[i].vek, pole[i].jmeno);
  }

  while(1) {
    printf("Zadej vek (0 - 99): ");
    scanf("%d", &stari);
    if (stari < 0)
      break;

    p_clovek = (CLOVEK *) bsearch((void *) &stari,
               (void *)pole, MAX, sizeof(CLOVEK), search_vek);

    if (p_clovek != NULL) {
      printf("vek = %3d, jmeno: %s (poradi: %d)\n",
             p_clovek->vek, p_clovek->jmeno, p_clovek - pole);
    }
  }

  printf("Serazeno podle jmena\n");

  qsort((void *)pole, MAX, sizeof(CLOVEK), sort_jmeno);
  for (i = 0;  i < MAX;  i++) {
    printf("%2d: %3d - %s\n", i, pole[i].vek, pole[i].jmeno);
  }

  while(1) {
    printf("Zadej jmeno: ");
    scanf("%5s", jmn);
    if (jmn[0] == '*')
      break;

    p_clovek = (CLOVEK *) bsearch( (void *) jmn, (void *)pole,
                           MAX, sizeof(CLOVEK), search_jmeno);

    if (p_clovek != NULL) {
      printf("jmeno: %s - vek = %3d, (poradi: %d)\n",
             p_clovek->jmeno, p_clovek->vek, p_clovek - pole);
    }
  }
  return 0;
}

int sort_vek(const void *p_a, const void *p_b)
{
  CLOVEK *p_1 = (CLOVEK *) p_a,
         *p_2 = (CLOVEK *) p_b;

  if (p_1->vek < p_2->vek)
    return -1;
  else if (p_1->vek == p_2->vek)
    return 0;
  else
    return +1;
}

int search_vek(const void *p_a, const void *p_b)
{
  /* pomocny vypis pro ukazku prubehu hledani */
  printf("a = %2d  b = %2d\n",
         *(int *)p_a, ((CLOVEK *)p_b)->vek);

  if (*(int *)p_a < ((CLOVEK *)p_b)->vek)
    return -1;
  else if (*(int *)p_a == ((CLOVEK *)p_b)->vek)
    return 0;
  else
    return +1;
}

int sort_jmeno(const void *p_a, const void *p_b)
{
  return ( strcmp(((CLOVEK *)p_a)->jmeno,
                  ((CLOVEK *)p_b)->jmeno) );
}

int search_jmeno(const void *p_a, const void *p_b)
{
  /* pomocny vypis pro ukazku prubehu hledani */
  printf("a = %s  b = %s\n",
         (char *)p_a, ((CLOVEK *)p_b)->jmeno);

  return ( strcmp((char *)p_a, ((CLOVEK *)p_b)->jmeno) );
}

void nahodna_inicializace(void)
{
  int i, j;

  for (i = 0;  i < MAX;  i++) {
    pole[i].vek = rand() % 100;
    for (j = 0;  j < 5;  j++) {
      pole[i].jmeno[j] = rand() % 26 + 'a';
    }
    pole[i].jmeno[5] = '\0';
  }
}

