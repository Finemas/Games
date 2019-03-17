/*
 * s63a.c    v.2.0
 *
 * Umisteni vetve default
 * ======================
 */

#include <stdio.h>

int main()
{
  switch (getchar()) {
    default  :
      printf("Nestiskl jsi ani '1' ani '2'\n");
      break;

    case '1' :
      printf("Stiskl jsi '1'\n");
      break;

    case '2' :
      printf("Stiskl jsi '2'\n");
      break;
  }
  return 0;
}
