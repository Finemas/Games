/*
 * s154.c    v.2.0
 *
 * void jako pointer na ruzne datove typy
 * ======================================
 */

#include <stdio.h>

int main(void)
{
  int i;
  float f;
  void *p_void = &i;           /* p_void ukazuje na i */

  *(int *) p_void = 2;         /* nastaveni i na 2 */
  p_void = &f;                 /* p_void ukazuje na f */
  *(float *) p_void = 1.1;     /* nastaveni f na 1.1 */

  printf("i = %d, f = %f\n", i, f);
  return 0;
}

