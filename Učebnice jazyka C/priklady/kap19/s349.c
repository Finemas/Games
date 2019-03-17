/*
 * s349.c    v.2.0
 *
 * Parsovani retezce
 * =================
 */

#include <stdio.h>
#include <string.h>

int main(void)
{
  char s1[] = "nazdar ahoj,dobry-den";
  char s2[] = "qwx radzan";
  char s3[] = "qwxr";
  char s4[] = "od";
  int pozice;
  char *p_c;

  pozice = strspn(s1, s2);
  printf("Prvnich %d znaku s1 je obsazeno v s2\n", pozice);

  pozice = strcspn(s1, s3);
  printf("Prvnich %d znaku s1 neni obsazeno v s3\n", pozice);

  p_c = strpbrk(s1, s4);
  if (p_c != NULL)
    printf("Prvni shodny znak v s1 a v s4: %c\n", *p_c);
  else
    printf("Zadny shodny znak\n");

  p_c = strtok(s1, " ,-");       /* mezera, èárka, pomlèka */
  if (p_c != NULL)
    printf("%s\n", p_c);

  while ((p_c = strtok(NULL, " ,-")) != NULL)
    printf("%s\n", p_c);

  return 0;
}

