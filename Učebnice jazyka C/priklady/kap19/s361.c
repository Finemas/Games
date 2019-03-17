/*
 * s361.c    v.2.0
 *
 * Triky s mktime()
 * ================
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
  struct tm *p_pak;
  time_t ted, spusteni;

  time(&ted);
  printf("%s\n", ctime(&ted));
  p_pak = localtime(&ted);
  p_pak->tm_min += 2;       /* prirustkove */
/*  p_pak->tm_hour = 20;       absolutne   */
  spusteni = mktime(p_pak);
  while (difftime(time(NULL), spusteni) < 0)
    ;        /* prazdny cyklus cekani */

  time(&ted);
  printf("%s\n", ctime(&ted));
  return 0;
}

