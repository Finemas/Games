/*
 * s259.c    v.2.0
 *
 * Variantni zaznam pomoci struktur a unionu
 * =========================================
 */

#include <stdio.h>

typedef enum {
  FALSE, TRUE
} BOOLEAN;

typedef union {
  struct {
    int i, j;
  } v1;
  struct {
    float f, g;
  } v2;
} VARIANTY;

typedef struct {
  int a, b;                     /* spolecne polozky */
  BOOLEAN  cele;                /* rozhodovaci prvek */
  VARIANTY var;
} ABC;

int main(void)
{
  ABC x;

  x.a = 1;
  printf("a = %d\tb = %d\ti = %d\tj = %d\tf = %f\tg = %f\n",
         x.a, x.b, x.var.v1.i, x.var.v1.j, x.var.v2.f, x.var.v2.g);

  x.b = 2;
  printf("a = %d\tb = %d\ti = %d\tj = %d\tf = %f\tg = %f\n",
         x.a, x.b, x.var.v1.i, x.var.v1.j, x.var.v2.f, x.var.v2.g);

  x.cele = TRUE;
  x.var.v1.i = 3;
  printf("a = %d\tb = %d\ti = %d\tj = %d\tf = %f\tg = %f\n",
         x.a, x.b, x.var.v1.i, x.var.v1.j, x.var.v2.f, x.var.v2.g);

  x.var.v1.j = 4;
  printf("a = %d\tb = %d\ti = %d\tj = %d\tf = %f\tg = %f\n",
         x.a, x.b, x.var.v1.i, x.var.v1.j, x.var.v2.f, x.var.v2.g);

  /* spravna prace s jednotlivymi polozkami podle hodnoty
     rozhodovaciho prvku */
  if (x.cele == TRUE) {
    printf("a = %d\tb = %d\ti = %d\tj = %d\n",
           x.a, x.b, x.var.v1.i, x.var.v1.j);
  }
  else {
    printf("a = %d\tb = %d\tf = %f\tg = %f\n",
            x.a, x.b, x.var.v2.f, x.var.v2.g);
  }

  x.cele = FALSE;
  x.var.v2.f = 5.6;
  printf("a = %d\tb = %d\ti = %d\tj = %d\tf = %f\tg = %f\n",
         x.a, x.b, x.var.v1.i, x.var.v1.j, x.var.v2.f, x.var.v2.g);

  x.var.v2.g = 7.8;
  printf("a = %d\tb = %d\ti = %d\tj = %d\tf = %f\tg = %f\n",
         x.a, x.b, x.var.v1.i, x.var.v1.j, x.var.v2.f, x.var.v2.g);

  /* spravna prace s jednotlivymi polozkami podle hodnoty
     rozhodovaciho prvku */
  if (x.cele == TRUE) {
    printf("a = %d\tb = %d\ti = %d\tj = %d\n",
           x.a, x.b, x.var.v1.i, x.var.v1.j);
  }
  else {
    printf("a = %d\tb = %d\tf = %f\tg = %f\n",
            x.a, x.b, x.var.v2.f, x.var.v2.g);
  }
  return 0;
}

