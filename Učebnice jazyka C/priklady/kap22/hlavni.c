/*
 * hlavni.c
 */

#include <stdio.h>

#include "ahoj.h"
#include "nazdar.h"
#include "cao.h"
#include "max.h"

int i;

int main(void)
{
  printf("Hlavni program:\n");

  for (i = 0;  i < MAX;  i++) {
    ahoj(a);
    nazdar(n);
    cao(c);
    putchar('\n');
  }
}
