/*
 * cv12.c    v.2.0
 *
 * Funkce pro vlozeni retezce do retezce
 * =====================================
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX  100             /* max. delka retezce */

/* uplny funkcni prototyp */
void strins(char *s1, char *s2, int i);

int main(void)
{
  char str1[MAX] = "Jazyk C - nemozne!";
  char str2[MAX] = " dokaze i";

  puts(str1);
  strins(str1, str2, 9);
  puts(str1);
  return 0;
}

void strins(char *s1, char *s2, int i)
{
  char pom[MAX];

  strcpy(pom, &s1[i]);          /* docasna uschova druhe casti */
  s1[i] = '\0';
  strcat(s1, s2);
  strcat(s1, pom);
}

