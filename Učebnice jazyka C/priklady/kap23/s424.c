/*
 * s421.c    v.2.0
 *
 * Vstupy a vystupy pro vicebajtove znaky
 * ======================================
 */

#include <stdio.h>
#include <wchar.h>

int main(void)
{
  FILE *fr, *fw;
  wchar_t wstr[100];

  if ((fr = fopen("unicode.txt", "r")) == NULL) {
    printf("neotevren\n");
    return 1;
  }
  if ((fw = fopen("velka.txt", "w")) == NULL) {
    printf("neotevren\n");
    return 1;
  }

  fwprintf(fw, L"%d, %f\n", 123, 3.14);
  fgetws(wstr, 100, fr);
  fputws(wstr, fw);

  fclose(fw);
  fclose(fr);

  return 0;
}

