//
// Created by Jan Fineas Provaznik on 04/11/2018.
//


#include <stdio.h>

int main()
{
    int no1, no2;
    char op;

    printf("Enter two numbers and operations:\n");
    if( scanf(" %d %c %d", &no1, &op, &no2) != 3 || no1 <= 0 || no2 <= 0)
    {
        printf("Invalid inputs.\n");
        return 1;
    }

    switch(op) {
        case '+':
            printf("%d + %d = %d\n", no1, no2, no1 + no2); break;
        case '-':
            printf("%d - %d = %d\n", no1, no2, no1 - no2); break;
        case '*':
            printf("%d * %d = %d\n", no1, no2, no1 * no2); break;
        case '/':
            printf("%d / %d = %d\n", no1, no2, no1 / no2); break;
        default:
            printf("Invalid operation");
    }

    return 0;
}
