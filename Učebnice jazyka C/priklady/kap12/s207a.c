/*
 * s207a.c    v.2.0
 *
 * Vlastnosti funkce fgets()
 * =========================
 */

#include <stdio.h>
#include <string.h>

#define MAX  5

int main(void)
{
  FILE * fr;
  char str[MAX];
  int i;

  if ((fr = fopen("cisla.txt", "r")) == NULL) {
    printf("cisla.txt neotevren\n");
    return 1;
  }

  while (fgets(str, MAX, fr) != NULL) {
    printf("'%s' : % d\t", str, strlen(str));
    for (i = 0;  i < strlen(str);  i++) {
      printf("%02X ", str[i]);
    }
    putchar('\n');
  }

  if (fclose(fr) == EOF) {
    printf("cisla.txt neotevren\n");
    return 1;
  }

  return 0;
}
