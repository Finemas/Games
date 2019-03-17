/*
 * aserce.c    v.2.0
 *
 * Ukazka pouziti assert() pro kontrolu mezi pole
 * ==============================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX   10

int main(int argc, char *argv[])
{
  int pole[MAX];
  int index, hodnota;

  if (argc != 3) {
    fprintf(stderr, "Pouziti:  %s index hodnota\n", argv[0]);
    exit(1);
  }

  index = atoi(argv[1]);
  hodnota = atoi(argv[2]);

  assert(index >= 0  &&  index < MAX);

  pole[index] = hodnota;
  printf("pole[%d] = %d\n", index, pole[index]);

  return 0;
}

