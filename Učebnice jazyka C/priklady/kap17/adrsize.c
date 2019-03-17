/*
 * adrsize.c
 *
 * Rekurzivni vypis adresare a jeho velikosti
 * ==========================================
 *
 * 11.2003 P.Herout
 *
 */

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
/* #include <sys/dir.h>
*/
#include <dirent.h>

#ifndef MAXPATHLEN
  #define MAXPATHLEN  1000
#endif

void vypis_adresar(char *path);

static unsigned long celkove_byte = 0;
static jen_velikost = 0;


int main(int argc, char *argv[])
{
  char *path = NULL;
  int  i;
  
  for (i = 1;  i < argc;  i++) {
    if (strcmp(argv[i], "-s") == 0)
      jen_velikost = 1;
    else if (strcmp(argv[i], "-h") == 0) {
      printf("\n adrsize [path] [-s] [-h]"
             "\n   vypis velikosti vsech souboru a vnorenych adresaru v ./"
             "\n      path  vypis jineho adresare"
             "\n      -s    vypis jen nazvu podadresaru a jejich velikosti"
             "\n      -h    tato napoveda\n\n");
      return 0;
    }
    else
      path = argv[i];
  }

  if (path == NULL)
    path = ".";

  
  vypis_adresar(path);

  if (jen_velikost == 1)
    putchar('\n');
  
  printf("\nCelkova velikost vsech souboru a adresaru: %lu [B]\n\n",
         celkove_byte);

  return 0;
}

void vypis_adresar(char *path)
{
  DIR            *p_dir;
  struct dirent  *p_d;
  struct stat    s_buf;
  char           buf[MAXPATHLEN];
  unsigned long  velikost_adr = 0;
  int            pocet_souboru = 0;
    
  if (stat(path, &s_buf)
      ||  (s_buf.st_mode & S_IREAD) == 0) {
    printf("ERR: neni pravo pristupu k adresari\n");
    return;
  }

  if ((p_dir = opendir(path)) == NULL) {
    printf("%s - ERR: adresar nelze otevrit\n", path);
    return;
  }

  printf("\n%s/", path);
  if (jen_velikost == 0)
    putchar('\n');
  
  /* vypis vsech souboru */
  while ((p_d = readdir(p_dir)) != NULL) {
    sprintf(buf, "%s/%s", path, p_d->d_name);
    errno = 0;
    if (stat(buf, &s_buf) == -1) {
      printf("ERR: nelze zjistit stav (%d) - %s - %s\n", 
              errno, strerror(errno), p_d->d_name);
    }

    velikost_adr += s_buf.st_size;  /* pocita se i misto pro podadresare */
    celkove_byte += s_buf.st_size;
    if ((s_buf.st_mode & S_IFDIR) == 0) {
      /* neni to adresar */
      pocet_souboru++;
      if (jen_velikost == 0)
        printf("\t %8ld %s\n", s_buf.st_size, p_d->d_name);
    }
  }  
  if (jen_velikost == 0)
    printf("  Size:\t %8lu [B]\n", velikost_adr);
  else 
    printf(" \t%8lu [B],\t%3d souboru", velikost_adr, pocet_souboru);

  /* nastaveni na zacatek adresare */
  rewinddir(p_dir);

  while ((p_d = readdir(p_dir)) != NULL) {
    sprintf(buf, "%s/%s", path, p_d->d_name);
    stat(buf, &s_buf);
    if ((s_buf.st_mode & S_IFDIR) != 0) {
      /* je to adresar */

      if (strcmp(p_d->d_name, ".") == 0
          ||  strcmp(p_d->d_name, "..") == 0) {
        /* je to aktualni nebo rodicovsky adresar */
        continue;
      }

      /* rekurzivni vypis noveho adresare */
      vypis_adresar(buf);
    }
  }
  closedir(p_dir);
}

