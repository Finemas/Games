/*
 * s297.c    v.2.0
 *
 * Test stavu klavesnice
 * =====================
 */

#include <stdio.h>
#include <fcntl.h>
#include <termios.h>

int kbhit(void)
{
  char c;
  static struct termios new_term;
  static struct termios old_term;
  static int handle;
  static int init = 0;

  fflush(stdout);

  if (init == 0) {
    init = 1;
    if ((handle = open("/dev/tty", O_RDWR | O_SYNC)) == 0) {
      fprintf(stderr, "Nelze cist z terminalu!\n");
      exit(1);
    }
    else {
      tcgetattr(handle, &old_term);
      new_term = old_term;
      new_term.c_lflag &= ~ICANON;
      new_term.c_lflag &= ~ECHO;
      new_term.c_cc[VMIN] = 0;
      new_term.c_cc[VTIME] = 1;
    }
  }

  tcsetattr(handle, TCSANOW, &new_term);
  if (read(handle, &c, 1) <= 0) {
    c = 0;
  }
  else {
    ungetc(c, stdin);
  }
  tcsetattr(handle, TCSANOW, &old_term);

  return c;
}

int main(void)
{
  int c;

  while(1) {
    putchar('>');

    if (kbhit() != 0) {
       c = getchar();
       printf("Stisknuta klavesa - '%c'", c);

       if (c == 'Z')
         break;
    }
    printf("<\n");
  }
  return 0;
}

