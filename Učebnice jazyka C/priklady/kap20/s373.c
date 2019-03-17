/*
 * s373.c    v.2.0
 *
 * Parametry ruzneho typu a neznameho poctu
 * ========================================
 */

#include <stdio.h>
#include <stdarg.h>

typedef enum {
  USPECH, CHYBA
} VYSLEDEK;

/* ukazka funkcniho prototypu s vypustkou */
VYSLEDEK sumace(int *p_cele, double *p_real, char *format, ...);

int main(void)
{
  int    s_cele;
  double s_real;

  /* vse v poradku */
  if (sumace(&s_cele, &s_real, "crrc", 1, 1.1, 2.2, 2) == CHYBA)
    fprintf(stderr, "Neznamy parametr\n");
  else
    printf("Suma_c = %d \t suma_r = %f\n", s_cele, s_real);

  /* vice parametru, nez je ocekavano */
  if (sumace(&s_cele, &s_real, "crr", 1, 1.1, 2.2, 2) == CHYBA)
    fprintf(stderr, "Neznamy parametr\n");
  else
    printf("Suma_c = %d \t suma_r = %f\n", s_cele, s_real);

  /* mene parametru, nez je ocekavano */
  if (sumace(&s_cele, &s_real, "crrc", 1, 1.1, 2.2) == CHYBA)
    fprintf(stderr, "Neznamy parametr\n");
  else
    printf("Suma_c = %d \t suma_r = %f\n", s_cele, s_real);

  /* chybny typ parametru */
  if (sumace(&s_cele, &s_real, "cdrc", 1, 1.1, 2.2, 2) == CHYBA)
    fprintf(stderr, "Neznamy parametr\n");
  else
    printf("Suma_c = %d \t suma_r = %f\n", s_cele, s_real);

  return 0;
}

/* scita pouze parametry typu int    (= c - cele)
 *                       nebo double (= r - realne)
 * vraci CHYBA v pripade chybneho znaku v retezci format
 * v pripade uspechu vraci USPECH
 */
VYSLEDEK sumace(int *p_cele, double *p_real, char *format, ...)
{
  va_list  argumenty;
  char *p_str;

  /* nulovani sumacnich parametru */
  *p_cele = 0;
  *p_real = 0.0;

  va_start(argumenty, format);
  for (p_str = format;  *p_str != '\0';  p_str++) {
    switch (*p_str) {
      case 'c' :                /* cele cislo */
        *p_cele += va_arg(argumenty, int);
        break;

      case 'r' :                /* realne cislo */
        *p_real += va_arg(argumenty, double);
        break;

      default :
        va_end(argumenty);
        return (CHYBA);
    }
  }
  va_end(argumenty);
  return (USPECH);
}

