/*
 * s418.c    v.2.0
 *
 * Vnorene funkce
 * ==============
 */

#include <stdio.h>

void vnejsi(int param)
{
  int lokalni = 5;
  int vnitrni(void)
  {
    printf("vnitrni %d\n", param);
    return lokalni * param;
  }

  printf("vnejsi %d - vnitrni %d\n", param, vnitrni());
}

int main(int argc)
{

  int vnitrni_main1(void) {
    void vnitrni_main2(void)
    {
      printf("vnitrni_main2 %d\n", argc);
    }

    printf("vnitrni_main1 %d\n", argc);
    vnitrni_main2();
    return 1;
  }

  printf("vnitrni_main1 z main() -> %d\n", vnitrni_main1());
/* NELZE
  printf("vnitrni_main2 z main() -> ");
  vnitrni_main2();
*/

  printf("vnejsi z main() -> ");
  vnejsi(3);

/* NELZE
  printf("vnitrni_z_vnejsi z main() -> ");
  vnitrni();
*/

  return 0;
}

