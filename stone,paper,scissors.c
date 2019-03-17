//
// Created by Jan Fineas Provaznik on 04/11/2018.
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*hra kamen, nuzky, papir*/


int main() {
	srand(time(NULL));

	int tah = 0;
	int random = rand() % 3;

	printf("Zadej cislo tveho tahu:\n");
	printf("0 = kamen\n1 = nuzky\n2 = papir\n----------\n");

	scanf("%d", &tah);

	printf("Tah protihrace je %d\n", random);

	switch(tah)
	{
		case 0:
			if(random == 1)
			{
				printf("Vyhral si!\n");
			}
			else if(random == 2) {
				printf("Prohral si\n");
			}
			else {
				printf("Remiza\n");
			}
			break;

		case 1:
			if(random == 2)
			{
				printf("Vyhral si!\n");
			}
			else if(random == 0) {
				printf("Prohral si\n");
			}
			else {
				printf("Remiza\n");
			}
			break;

		case 2:
			if(random == 0)
			{
				printf("Vyhral si!\n");
			}
			else if(random == 1) {
				printf("Prohral si\n");
			}
			else {
				printf("Remiza\n");
			}
			break;
	}

	return 0;
}
