/*
 * cv08.c    v.2.0
 *
 * Zkraceny zapis testu na nulu
 * ============================
 *
 */

#include <stdio.h>

int main(void)
{
  int vyraz;

  printf("Splnene podminky:\n");
  /* nulova hodnota */
  vyraz = 0;
  if (vyraz != 0)
    printf("if (%d != 0)\n", vyraz);
  if (vyraz)
    printf("if (%d)\n", vyraz);
  if (vyraz == 0)
    printf("if (%d == 0)\n", vyraz);
  if (!vyraz)
    printf("if (!%d)\n", vyraz);

  putchar('\n');
  /* nenulova hodnota */
  vyraz = 1;
  if (vyraz != 0)
    printf("if (%d != 0)\n", vyraz);
  if (vyraz)
    printf("if (%d)\n", vyraz);
  if (vyraz == 0)
    printf("if (%d == 0)\n", vyraz);
  if (!vyraz)
    printf("if (!%d)\n", vyraz);
  return 0;
}

