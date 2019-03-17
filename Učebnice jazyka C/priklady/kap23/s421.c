/*
 * s421.c    v.2.0
 *
 * Vicebajtove retezcove konstanty
 * ===============================
 */

#include <stdio.h>
#include <wchar.h>

int main(void)
{
  wchar_t wstr1[] =  L"Cesky\n";  /* Èeský! */
  wchar_t wstr2[] = {'\u010C', 'e', 's', 'k', '\u00FD', '\x21', '\n'};  

  int pocet_bytu = sizeof(wstr1);

  printf("velikost wchar_t [bytu] = %d\n", sizeof(wchar_t));
  printf("pocet bytu = %d\n", pocet_bytu);

  return 0;
}

