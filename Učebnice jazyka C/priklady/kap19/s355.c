/*
 * s355.c    v.2.0
 *
 * Presne mereni doby behu programu
 * ================================
 *
 * Pozor, pouziva nestandardni C funkce
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/unistd.h>

#define MAX             1000
#define VNITRNI_SMYCKA  1000000

int main(int argc, char *argv[])
{
  unsigned long int i, j, vnejsi_smycka;
  int tiku_za_sekundu;
  struct tms casova_struktura;
  clock_t celkovy_z, celkovy_k;
  clock_t program_z, program_k;

  vnejsi_smycka = (argc == 1) ? MAX : atol(argv[1]);
  tiku_za_sekundu = sysconf(_SC_CLK_TCK);

  celkovy_z = times(&casova_struktura);
  program_z = casova_struktura.tms_utime;

  for (i = 0;  i < vnejsi_smycka;  i++) {
    for (j = 0;  j < VNITRNI_SMYCKA;  j++) {
      i++;
      i--;
    }
  }

  celkovy_k = times(&casova_struktura);
  program_k = casova_struktura.tms_utime;

  printf("celkovy = %.3f [sec]\n",
      (celkovy_k - celkovy_z) / (double) tiku_za_sekundu);
  printf("program = %.3f [sec]\n",
      (program_k - program_z) / (double) tiku_za_sekundu);

  return 0;
}

