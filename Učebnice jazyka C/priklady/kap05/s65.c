/*
 * s65.c    v.2.0
 *
 * Vhodne pouziti prikazu goto
 * ===========================
 */

#include <stdio.h>

int main()
{
  int i, j, k;
  int x[10], a[10], b[10];      /* definice poli */

  /* inicializace poli */
  for (i = 0;  i < 10;  i++) {
    x[i] = i + 1;
    a[i] = i * 2;
    b[i] = i * i;
  }

  x[5] = 0;                     /* nulovy delitel */

  for (i = 0;  i < 10;  i++) {
    for (j = 0;  j < 10;  j++) {
      for (k = 0;  k < 10;  k++) {
        if (x[k] == 0)
          goto error;
        a[i] = a[i] + b[j] / x[k];
      }
    }
  }
  goto dalsi_vypocet;

  error:
  printf("Nulovy delitel\n");
  goto konec;

  dalsi_vypocet:
  /* tisk pole */
  for (i = 0;  i < 10;  i++)
    printf("%d ", a[i]);

  konec:
  return 0;
}
