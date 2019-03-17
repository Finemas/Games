/*
 * s315.c    v.2.0
 *
 * Velikosti a casy souboru
 * ========================
 */

#include <stdio.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
  DIR            *p_dir;
  struct dirent  *p_dirent;
  struct stat    s_buf;
  char           plne_jmeno[1000];
  struct tm      tm;

  p_dir = opendir(argv[1]);
  if (p_dir == NULL) {
    printf("Adresar '%s' neexistuje\n", argv[1]);
    return 1;
  }

  while ((p_dirent = readdir(p_dir)) != NULL) {
    sprintf(plne_jmeno, "%s/%s", argv[1], p_dirent->d_name);
    stat(plne_jmeno, &s_buf);
    if ((s_buf.st_mode & S_IFDIR) != 0)
      continue;          /* adresar - prechod na dalsi polozku */
    printf("%s, ", p_dirent->d_name);
    printf("%lu, ", s_buf.st_size);
    tm = *localtime(&s_buf.st_mtime);
    printf("%02d.%02d.%4d\n", tm.tm_mday, tm.tm_mon + 1,
                              tm.tm_year + 1900);
  }

  return 0;
}

