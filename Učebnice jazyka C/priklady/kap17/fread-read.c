/*
 * fread-read.c
 *
 * Porovnavani rychlosti pro fread() a read()
 * ==========================================
 *
 * (c) P.Herout - 11.2002
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <fcntl.h>
#include <sys/times.h>
#include <sys/unistd.h>

#define MAX  10
#define JMENO "data.bin"

char data[BUFSIZ];

int main(void)
{
  int i, j, n;
  long int size, k;
  double cas, prum;
  FILE *fr;
  int hand;

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
  for (j = 1;  j <= MAX;  j++) {
    (void) times(&casova_struktura);
    program_z = casova_struktura.tms_utime;

    k = 0;
    for (i = 1;  i <= MAX;  i++) {
      fseek(fr, 0L, SEEK_SET);
      while ((n = fread(data, 1, BUFSIZ, fr)) == BUFSIZ)
        k += BUFSIZ;
      k += n;
    }

    (void) times(&casova_struktura);
    program_k = casova_struktura.tms_utime;
    cas = ((program_k - program_z) / (double) sysconf(_SC_CLK_TCK)) * 1000;
    prum += cas;
    printf("%d. %.0f (%s) ", j, cas, (k == size * MAX) ? "OK" : "chyba");
    fflush(stdout);
  }

  printf("\nPrumer fread(): %.0f [msec]\n", prum / MAX);

  if (fclose(fr) == EOF)
    printf("%s nezavren\n", JMENO);

/* UNIX I/O */
  if ((hand = open(JMENO, O_RDONLY)) == -1) {
    printf("%s neotevren\n", JMENO);
    exit(1);
  }

  prum = 0.0;
  for (j = 1;  j <= MAX;  j++) {
    (void) times(&casova_struktura);
    program_z = casova_struktura.tms_utime;

    k = 0;
    for (i = 1;  i <= MAX;  i++) {
      lseek(hand, 0L, SEEK_SET);
      while ((n = read(hand, data, BUFSIZ)) == BUFSIZ)
        k += BUFSIZ;
      k += n;
    }

    (void) times(&casova_struktura);
    program_k = casova_struktura.tms_utime;
    cas = ((program_k - program_z) / (double) sysconf(_SC_CLK_TCK)) * 1000;
    prum += cas;
    printf("%d. %.0f (%s) ", j, cas, (k == size * MAX) ? "OK" : "chyba");
    fflush(stdout);
  }

  printf("\nPrumer  read(): %.0f [msec]\n", prum / MAX);

  close(hand);

  return 0;
}

