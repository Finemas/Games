/*
 * cv04.c    v.2.0
 *
 * Definice vlastnich maker pro praci se znaky
 * ===========================================
 *
 */

#include <stdio.h>
#include <ctype.h>

#define je_velke(c)  (((c) >= 'A'  &&  (c) <= 'Z') ? 1 : 0)

#define taky_velke(c)  ((isupper(c)) ? 1 : 0)

int main(void)
{
  int c;

  c = 'B';
  if (je_velke(c))
    printf("Znak '%c' je velke pismeno\n", c);
  else
    printf("Znak '%c' neni velke pismeno\n", c);

  c = 'e';
  if (je_velke(c))
    printf("Znak '%c' je velke pismeno\n", c);
  else
    printf("Znak '%c' neni velke pismeno\n", c);

  c = 'B';
  if (taky_velke(c))
    printf("Znak '%c' je velke pismeno\n", c);
  else
    printf("Znak '%c' neni velke pismeno\n", c);

  c = 'e';
  if (taky_velke(c))
    printf("Znak '%c' je velke pismeno\n", c);
  else
    printf("Znak '%c' neni velke pismeno\n", c);

  return 0;
}

