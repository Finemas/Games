/*
 * cao.c
 */

#include <stdio.h>

#include "cao.h"
#include "max.h"

int c = 4;

void cao(int c)
{
  int i;

  for (i = 0;  i < c  &&  i < MAX;  i++) {
    printf("%d: %s - ", i, CAO);
  }
}
