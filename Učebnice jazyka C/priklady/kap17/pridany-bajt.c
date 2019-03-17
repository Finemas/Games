/*
 * pridany-bajt.c
 *
 * Ukazka jak fread() pridava v textovem rezimu '\r' pred '\n'
 * ===========================================================
 *
 */
 
#include <stdio.h>

int main(void)
{
  FILE *fr, *fw;
  int i = '\n';

  if ((fw = fopen("data.txt", "w")) == NULL) {
    printf("neotevren\n");
    return 1;
  }
  if(fwrite((void *) &i, sizeof(i), 1, fw) != 1) {
    printf("malo zapsanych polozek\n");
  }

  fclose(fw);

  if ((fr = fopen("data.txt", "r")) == NULL) {
    printf("neotevren\n");
    return 1;
  }

  i = 0;
  if(fread((void *) &i, sizeof(i), 1, fr) != 1) {
    printf("malo prectenych polozek\n");
  }
  printf("i = %d\n", i);
  
  fclose(fr);

  return 0;
}
