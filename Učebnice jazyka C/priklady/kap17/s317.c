/*
 * s317.c    v.2.0
 *
 * Udaje o souborech a adresarich ve Windows
 * =========================================
 */

#include <stdio.h>
#include <string.h>
#include <io.h>
#include <time.h>

int main(int argc, char **argv)
{
  struct _finddata_t data;
  struct tm      tm;
  char maska[] = "*.*";
  char adresar[1000];
  intptr_t vysledek;
  
  if (argc == 1)
    strcpy(adresar, maska);
  else
    sprintf(adresar, "%s/%s", argv[1], maska);

  vysledek = _findfirst(adresar, &data);
  if (vysledek == -1) {
    printf("Zadny soubor nevyhovuje masce '%s'\n", maska);
    return 1;
  }
  while (_findnext(vysledek, &data) == 0) {
    if ((data.attrib & _A_SUBDIR) != 0)
      continue;                         /* adresar */

    printf("%s, ", data.name);
    printf("%lu, ", data.size);
    tm = *localtime(&data.time_write);
    printf("%02d.%02d.%4d\n", tm.tm_mday, tm.tm_mon + 1,
                              tm.tm_year + 1900);
  }

  _findclose(vysledek); 
   
  return 0;
}

