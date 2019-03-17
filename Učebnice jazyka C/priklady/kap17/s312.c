/*
 * s312.c    v.2.0
 *
 * Jmena souboru a podadresaru v aktualnim adresari
 * ================================================
 */

#include <stdio.h>

#include <dirent.h>

#define AKTUALNI_ADRESAR  "."

int main(void)
{
  DIR            *p_dir;
  struct dirent  *p_dirent;

  p_dir = opendir(AKTUALNI_ADRESAR);
  while ((p_dirent = readdir(p_dir)) != NULL) {
    printf("%s\n", p_dirent->d_name);
  }

  closedir(p_dir);   /* nepovinne */
  return 0;
}

