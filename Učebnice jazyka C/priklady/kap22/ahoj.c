/*
 * ahoj.c
 */

#include <stdio.h>

#include "ahoj.h"
#include "nazdar.h"
#include "cao.h"
#include "max.h"

int a = 3;

void ahoj(int a)
{
  int i;

  for (i = 0;  i < a  &&  i < MAX;  i++) {
    printf("%d: %s - ", i, AHOJ);
    nazdar(i);
    cao(i);
  }
}
