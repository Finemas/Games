/*
 * buffer-blok.c
 *
 * Porovnavani rychlosti pri zvetsovani bufferu
 * ============================================
 *
 * (c) P.Herout - 11.2002
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/unistd.h>

#define MAX  10
#define ZMEN 7
#define JMENO "data.bin"

int main(void)
{
  int i, j, n;
  long int size, k;
  double cas, prum;
  char *p_buf;     /* buffer */
  char *p_data;    /* nacitana data */
  int buf_size;
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

  if (fclose(fr) == EOF)
    printf("%s nezavren\n", JMENO);

  buf_size = BUFSIZ * (1 << (ZMEN - 1));
  if ((p_buf = (char *) malloc(buf_size)) == NULL) {
    printf("Malo pameti pro p_buf\n");
    exit(1);
  }
  if ((p_data = (char *) malloc(buf_size)) == NULL) {
    printf("Malo pameti pro p_data\n");
    exit(1);
  }

  for (i = 0;  i < ZMEN;  i++) {
    buf_size = BUFSIZ * (1 << i);

    prum = 0.0;
    for (j = 1;  j <= MAX;  j++) {
      if ((fr = fopen(JMENO, "rb")) == NULL) {
        printf("%s neotevren\n", JMENO);
        exit(1);
      }
      if (setvbuf(fr, p_buf, _IOFBF, buf_size) != 0) {
        printf("setvbuf neuspesny - %d\n", buf_size);
        exit(1);
      }

      (void) times(&casova_struktura);
      program_z = casova_struktura.tms_utime;

      k = 0;
      while ((n = fread(p_data, 1, buf_size, fr)) == buf_size)
        k += buf_size;
      k += n;

      (void) times(&casova_struktura);
      program_k = casova_struktura.tms_utime;
      cas = ((program_k - program_z) / (double) sysconf(_SC_CLK_TCK)) * 1000;
      prum += cas;
      printf("%d.: %.0f (%s) ", j, cas, (k == size) ? "OK" : "chyba");
      fflush(stdout);

      if (fclose(fr) == EOF)
        printf("%s nezavren\n", JMENO);
    }

    printf("\nPrumer %5d: %.0f [msec]\n", buf_size, prum / MAX);
  }

  free((void *) p_buf);

  return 0;
}
