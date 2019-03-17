/*
 * fgetc-getc.c
 *
 * Porovnavani rychlosti getc() a fgetc()
 * ======================================
 *
 * (c) P.Herout - 11.2002
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/unistd.h>

#define MAX 11
#define JMENO "data.bin"

int main(void)
{
  int i, c;
  long int size, k;
  double cas, prum;
  FILE *fr;

  /* pro mereni casu */
  struct tms casova_struktura;
  clock_t program_z, program_k;

  if ((fr = fopen(JMENO, "rb")) == NULL) {
    printf("%s neotevren\n", JMENO);
    exit(1);
  }

  fseek(fr, 0L, SEEK_END);
  size = ftell(fr);
  printf("Size = %ld [B]\n", size);

  prum = 0.0;
  for (i = 1;  i <= MAX;  i++) {
    fseek(fr, 0L, SEEK_SET);
    (void) times(&casova_struktura);
    program_z = casova_struktura.tms_utime;

    k = 0;
#ifdef FGETC
    while ((c = fgetc(fr)) != EOF)
#else
    while ((c = getc(fr)) != EOF)
#endif
      k++;

    (void) times(&casova_struktura);
    program_k = casova_struktura.tms_utime;
    cas = ((program_k - program_z) / (double) sysconf(_SC_CLK_TCK)) * 1000;
    prum += cas;
    printf("%2d.: %.0f [msec] (%s)\n", i, cas, (k == size) ? "OK" : "chyba");
  }

#ifdef FGETC
  printf("Prumer fgetc(): %.0f [msec]\n", prum / MAX);
#else
  printf("Prumer  getc(): %.0f [msec]\n", prum / MAX);
#endif

  if (fclose(fr) == EOF)
    printf("%s nezavren\n", JMENO);

  return 0;
}

