#include <stdio.h>

#define MAX_ARRAY 5

int readValues( int * field )
{
	int x = 0, i = 0;

	printf( "Zadejte cisla ( max. %d )\n"
					"zakoncenou nulou\n", MAX_ARRAY );
	do {
		scanf( "%d", &x );
		field[i++] = x;
	} while( x != 0 && i < MAX_ARRAY );
}

int countAverage( int * field, int * avgPtr )
{
	int avg = *avgPtr;

	for( int i = 0; i < MAX_ARRAY ;i ++ )
		avg += field[i];
	avg /= MAX_ARRAY;
	*avgPtr = avg;
}

void printResult( int * field, int * avgPtr )
{
	for( int i = 0; i < MAX_ARRAY; i++ )
		printf( "diference %d\n", field[i] - *avgPtr );
	printf( "Prumer cisel je %d\n", *avgPtr );
}

int main(void)
{
	int field[MAX_ARRAY];
	int avg = 0;

	readValues(field);
	countAverage(field, &avg);
	printResult(field, &avg);

	return 0;
}
