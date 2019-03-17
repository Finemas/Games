#include <stdio.h>

#define DAYS_MAX 100

int main ( void )
{
  int temp[DAYS_MAX], n, avg=0, i;

  printf ( "Napis pocet dni (1 .. %d):\n", DAYS_MAX );
  scanf ( "%d", &n );

  printf ( "Napis teploty (%d x):\n", n );
  for ( i = 0; i < n; i ++ )
    scanf ( "%d", &temp[i] );
  for ( i = 0; i < n; i ++ ) avg += temp[i];
  avg /= n;

  printf ( "Prumerna teplota: %d\n", avg );

  printf ( "diference:\n" );
  for ( i = 0; i < n; i ++ )
    printf ( "%d ", temp[i] - avg );
  printf( "\n" );

  return 0;
}
