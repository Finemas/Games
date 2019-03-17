/*
 * cv18.c    v.2.0
 *
 * Vliv pametove tridy register na rychlost programu
 * =================================================
 *
 */

#include <stdio.h>
#include <time.h>

#define MAX  100000

int gi, gj;                     /* globalni promenne */

int main(void)
{
  register int li;              /* lokalni promenna */
  register int lj;              /* lokalni promenna */

  time_t zac, kon;

  zac = time(NULL);
  for (gi = 0;  gi < MAX;  gi++) {
    for (gj = 0;  gj < MAX;  gj++) {
      gi = gi;
      gj = gj;
    }
  }
  kon = time(NULL);

  printf("Cykly s globalnimi promennymi trvaly %d sec\n",
          (kon - zac));

  zac = time(NULL);
  for (li = 0;  li < MAX;  li++) {
    for (lj = 0;  lj < MAX;  lj++) {
      li = li;
      lj = lj;
    }
  }
  kon = time(NULL);

  printf("Cykly s registrovymi promennymi trvaly %d sec\n",
          (kon - zac));

  return 0;
}

