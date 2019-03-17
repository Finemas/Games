/*
 * cv02.c    v.2.0
 *
 * Zakladni operace s retezci
 * ==========================
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX    20

int main(void)
{
  char s[MAX];
  char *p_c, *p_pom;

  strcpy(s, "Toto je priklad");
  printf("Prvni retezec: %s\n\n", s);

  if ((p_c = malloc(MAX)) == NULL) {
    printf("Malo pameti\n");
    return 1;
  }
  
  for (p_pom = s;  p_pom < s + MAX;  )
    *p_c++ = *p_pom++;

  /* prirazeni pocatecni adresy retezce pointeru */
  p_c -= MAX;
  printf("Druhy retezec: %s\n", p_c);

  free((void *) p_c);

  return 0;
}

