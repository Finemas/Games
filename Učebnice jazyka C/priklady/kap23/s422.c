/*
 * s422.c    v.2.0
 *
 * Testy vicebajtovych znaku
 * =========================
 */

#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

int main(void)
{
  wchar_t w1 = '1';
  wchar_t wv = L'\u010C';
  wchar_t wm;
  char c = 'a';
  wint_t wc;

  if (iswalnum(w1) != 0)
    printf("alfanumericky znak\n");
  if (iswupper(wv) != 0)
    printf("velke pismeno\n");
  wm = towlower(wv);
  printf("%04X -> %04X\n", (int) wv, (int) wm);
/*
  wc = btowc(c);
  c = wctob(w1);
*/
  return 0;
}

