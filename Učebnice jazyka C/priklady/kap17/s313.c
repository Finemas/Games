/*
 * s313.c    v.2.0
 *
 * Jmena souboru a podadresaru v libovolnem adresari
 * =================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <dirent.h>

int main(int argc, char **argv)
{
  DIR            *p_dir;
  struct dirent  *p_dirent;

  p_dir = opendir(argv[1]);
  if (p_dir == NULL) {
    printf("Adresar '%s' neexistuje nebo "
           "nemame pristupova prava na otevreni\n",
           argv[1]);
    return 1;
  }

  while ((p_dirent = readdir(p_dir)) != NULL) {
    printf("%s\n", p_dirent->d_name);
  }

  closedir(p_dir);   /* nepovinne */
  return 0;
}
