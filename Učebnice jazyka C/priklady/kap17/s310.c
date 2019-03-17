/*
 * s310.c    v.2.0
 *
 * Prace se souborem v UNIXu
 * =========================
 */

#include <stdio.h>
#include <io.h>
#include <fcntl.h>

int main(void)
{
  int handle;
  int i = 10;
  double d = 3.14159;

  handle = open("POKUS2.DAT", O_CREAT | O_RDWR);
  write(handle, &i, sizeof(i));   /* zapis dat do souboru */
  write(handle, &d, sizeof(d));
  close(handle);

  i = 0; d = 0.0;                 /* nulovani promennych */

  handle = open("POKUS2.DAT", O_RDONLY);
  read(handle, &i, sizeof(i));    /* cteni a zobrazeni dat */
  read(handle, &d, sizeof(d));
  close(handle);

  printf("Nactena data: i = %d, d = %f\n", i, d);
  return 0;
}
