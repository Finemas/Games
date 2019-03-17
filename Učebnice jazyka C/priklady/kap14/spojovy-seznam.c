/*
 * spojovy-seznam.c
 *
 * Vytvareni spojoveho seznamu a vyrazovani jeho prvku
 * ===================================================
 *
 * pridavna funkce je mereni casu
 *
 * (c) P.Herout - 11.2002
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/unistd.h>

/* VYPIS se definuje na prikazove radce prekladace -D VYPIS
#define VYPIS
*/

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


int main(int argc, char **argv)
{
  int i, n, k;
  PRVEK *p_prv, *p_akt, *p_pred;

  /* pro mereni casu */
  struct tms casova_struktura;
  clock_t program_z, program_k;

  if (argc >= 2) {
    sscanf(argv[1], "%d", &n);    
  }
  else {
    printf("Pocet prvku: ");
    scanf("%d", &n);
  }
  if (argc >= 3) {
    sscanf(argv[2], "%d", &k);    
  }
  else {
    printf("Kazdy k-ty vyradit (1 <= k <= %d): ", n);
    scanf("%d", &k);
  }

  (void) times(&casova_struktura);
  program_z = casova_struktura.tms_utime;

  p_prv = alokuj_a_testuj();
  p_prv->hodnota = 1;
  p_prv->p_dalsi = NULL;
  p_akt = p_prv;

  for (i = 2;  i <= n;  i++) {
    p_akt->p_dalsi = alokuj_a_testuj();
    p_akt = p_akt->p_dalsi;
    p_akt->hodnota = i;
    p_akt->p_dalsi = NULL;
  }

#ifdef VYPIS
  for (p_akt = p_prv;  p_akt != NULL;  p_akt = p_akt->p_dalsi) {
    printf("%2d [%p]\n", p_akt->hodnota, p_akt);
  }
#endif

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

#ifdef VYPIS
  for (p_akt = p_prv;  p_akt != NULL;  p_akt = p_akt->p_dalsi) {
    printf("%2d [%p]\n", p_akt->hodnota, p_akt);
  }
#endif

  (void) times(&casova_struktura);
  program_k = casova_struktura.tms_utime;
  printf("program = %.3f [sec]\n", 
                    (program_k - program_z) / (double) sysconf(_SC_CLK_TCK));

  return 0;
}
