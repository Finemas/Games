/*
 * s359.c    v.2.0
 *
 * Pouziti funkce strftime()
 * =========================
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
  time_t cas;
  struct tm *p_st_cas;
  char str[1000];
  size_t pocet;

  cas = time(NULL);
  p_st_cas = localtime(&cas);

  pocet = strftime(str, 1000, "rok = %Y", p_st_cas);
  printf("%s (%d znaku)\n", str, pocet);

  /* stary zpusob */
  printf("%d = rok\n", p_st_cas->tm_year + 1900);

  strftime(str, 1000, "Cas = %H:%M:%S, datum = %d.%m.%Y\n", p_st_cas);
  printf("%s", str);

  strftime(str, 1000, "Den = %A (%a), mesic = %B (%b)\n", p_st_cas);
  printf("%s", str);

  strftime(str, 1000, "Cas = %X, datum = %x\n", p_st_cas);
  printf("%s", str);

  strftime(str, 1000, "Datum i cas = %c\n", p_st_cas);
  printf("%s", str);

  strftime(str, 1000, "Hodiny (12h) = %I %p\n", p_st_cas);
  printf("%s", str);

  return 0;
}
