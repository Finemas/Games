/*
 * s232.c    v.2.0
 *
 * Ruzne zpusoby definice struktury
 * ================================
 */

#include <stdio.h>

int main(void)
{
  { /* blok */
    struct {
      int   vyska;
      float vaha;
    } pavel, honza, karel;

    pavel.vyska = 186;
    karel.vaha = 89.5;
    honza.vyska = pavel.vyska;
    printf("Pavel vyska: %d, Karel vaha: %.1f, Honza vyska: %d\n",
            pavel.vyska, karel.vaha, honza.vyska);
  }


  { /* blok */
    struct miry {
      int   vyska;
      float vaha;
    } pavel, honza, karel;

    pavel.vyska = 186;
    karel.vaha = 89.5;
    honza.vyska = pavel.vyska;
    printf("Pavel vyska: %d, Karel vaha: %.1f, Honza vyska: %d\n",
            pavel.vyska, karel.vaha, honza.vyska);
  }


  { /* blok */
    struct miry {             /* definice struktury */
      int   vyska;
      float vaha;
    };
    struct miry pavel;        /* definice promennych */
    struct miry honza, karel;
/*    miry pavel, honza, karel; */ /* chyba */

    pavel.vyska = 186;
    karel.vaha = 89.5;
    honza.vyska = pavel.vyska;
    printf("Pavel vyska: %d, Karel vaha: %.1f, Honza vyska: %d\n",
            pavel.vyska, karel.vaha, honza.vyska);
  }



  { /* blok */
    typedef struct {        /* definice typu struktury */
      int   vyska;
      float vaha;
    } MIRY;
    MIRY pavel, honza, karel; /* definice promennych */

    pavel.vyska = 186;
    karel.vaha = 89.5;
    honza.vyska = pavel.vyska;
    printf("Pavel vyska: %d, Karel vaha: %.1f, Honza vyska: %d\n",
            pavel.vyska, karel.vaha, honza.vyska);
  }


  { /* blok */
    typedef struct miry {   /* definice typu struktury */
      int   vyska;
      float vaha;
    } MIRY;
    MIRY pavel, honza, karel; /* definice promennych */

    pavel.vyska = 186;
    karel.vaha = 89.5;
    honza.vyska = pavel.vyska;
    printf("Pavel vyska: %d, Karel vaha: %.1f, Honza vyska: %d\n",
            pavel.vyska, karel.vaha, honza.vyska);
  }
  return 0;
}

