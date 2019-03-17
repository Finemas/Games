/*
 * s237.c        v.2.0
 *
 * Vytvareni spojoveho seznamu a vyrazovani jeho prvku
 * ===================================================
 */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct prvek {
  int hodnota;
  struct prvek *p_dalsi;
} PRVEK;

PRVEK *alokuj_a_testuj(void)
{
  PRVEK *p_pom;

  p_pom = (PRVEK *) malloc(sizeof(PRVEK));
  if (p_pom == NULL) {
    printf("Malo pameti\n");
    exit(1);
  }
  return p_pom;
}


int main(void)
{
  int i, n, k;
  PRVEK *p_prv, *p_akt, *p_pred;

  printf("Zadej pocet prvku seznamu: ");
  scanf("%d", &n);

  printf("Kazdy k-ty vyradit (1 <= k <= %d): ", n);
  scanf("%d", &k);

  /* vytvoreni prvniho prvku */
  p_prv = alokuj_a_testuj();
  p_prv->hodnota = 1;
  p_prv->p_dalsi = NULL;
  p_akt = p_prv;

  /* vytvoreni vsech dalsich prvku */
  for (i = 2;  i <= n;  i++) {
    p_akt->p_dalsi = alokuj_a_testuj();
    p_akt = p_akt->p_dalsi;
    p_akt->hodnota = i;
    p_akt->p_dalsi = NULL;
  }

  for (p_pred = p_akt = p_prv;  p_akt != NULL;  ) {
    if ((p_akt->hodnota % k) == 0) {
      if (p_prv == p_akt) {
        p_prv = p_akt->p_dalsi;
        p_pred = p_prv;
      }
      else {
        p_pred->p_dalsi = p_akt->p_dalsi;
      }

      free((void *) p_akt);
      p_akt = p_pred;
    }
    else {  /* nic se nevyhazovalo - normalni prechod na dalsi prvek */
      p_pred = p_akt;
      p_akt = p_akt->p_dalsi;
    }
  }

  for (p_akt = p_prv;  p_akt != NULL;  p_akt = p_akt->p_dalsi) {
    printf("%2d [%p]\n", p_akt->hodnota, p_akt);
  }

  /* zaverecne uvolneni pameti */
  for (p_akt = p_prv;  p_akt != NULL;  ) {
    p_prv = p_akt;
    p_akt = p_akt->p_dalsi;
    free((void *) p_prv);
  }
  return 0;
}

