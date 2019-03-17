/*
 * s314.c    v.2.0
 *
 * Rozliseni jmen souboru a podadresaru
 * ====================================
 */

#include <stdio.h>

#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  DIR            *p_dir;
  struct dirent  *p_dirent;
  struct stat    s_buf;
  char           plne_jmeno[1000];

  p_dir = opendir(argv[1]);
  if (p_dir == NULL) {
    printf("Adresar '%s' neexistuje\n", argv[1]);
    return 1;
  }

  printf("Podadresare:\n");
  while ((p_dirent = readdir(p_dir)) != NULL) {
    sprintf(plne_jmeno, "%s/%s", argv[1], p_dirent->d_name);
    stat(plne_jmeno, &s_buf);
    if ((s_buf.st_mode & S_IFDIR) != 0) {
      if (p_dirent->d_name[0] != '.')
        printf("%s\n", p_dirent->d_name);
    }
  }

  rewinddir(p_dir);

  printf("\nSoubory:\n");
  while ((p_dirent = readdir(p_dir)) != NULL) {
    sprintf(plne_jmeno, "%s/%s", argv[1], p_dirent->d_name);
    stat(plne_jmeno, &s_buf);
    if ((s_buf.st_mode & S_IFDIR) == 0) {
      printf("%s\n", p_dirent->d_name);
    }
  }

  return 0;
}

