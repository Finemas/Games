#include <stdio.h>
#include <stdlib.h>

void prepareBoard( int board[][26], int size )
{
    for( int i = 0; i < size; ++i ) {
        for( int j = 0; j < size; ++j ) {
            board[i][j] = 0;
        }
    }
}

char alphabet( int num )
{
    switch( num ) {
        case 1:
            return 'A';
        case 2:
            return 'B';
        case 3:
            return 'C';
        case 4:
            return 'D';
        case 5:
            return 'E';
        case 6:
            return 'F';
        case 7:
            return 'G';
        case 8:
            return 'H';
        case 9:
            return 'I';
        case 10:
            return 'J';
        case 11:
            return 'K';
        case 12:
            return 'L';
        case 13:
            return 'M';
        case 14:
            return 'N';
        case 15:
            return 'O';
        case 16:
            return 'P';
        case 17:
            return 'Q';
        case 18:
            return 'R';
        case 19:
            return 'S';
        case 20:
            return 'T';
        case 21:
            return 'U';
        case 22:
            return 'V';
        case 23:
            return 'W';
        case 24:
            return 'X';
        case 25:
            return 'Y';
        case 26:
            return 'Z';
        default:
            printf( "Neni" );
    }

    return 0;
}

int number( char let )
{
    switch( let ) {
        case 'A':
            return 1;
        case 'B':
            return 2;
        case 'C':
            return 3;
        case 'D':
            return 4;
        case 'E':
            return 5;
        case 'F':
            return 6;
        case 'G':
            return 7;
        case 'H':
            return 8;
        case 'I':
            return 9;
        case 'J':
            return 10;
        case 'K':
            return 11;
        case 'L':
            return 12;
        case 'M':
            return 13;
        case 'N':
            return 14;
        case 'O':
            return 15;
        case 'P':
            return 16;
        case 'Q':
            return 17;
        case 'R':
            return 18;
        case 'S':
            return 19;
        case 'T':
            return 20;
        case 'U':
            return 21;
        case 'V':
            return 22;
        case 'W':
            return 23;
        case 'X':
            return 24;
        case 'Y':
            return 25;
        case 'Z':
            return 26;
        default:
            printf( "Neni" );
    }

    return 0;
}

void printBoard( int board[][26], int size )
{
    int i, j;

    printf( "     " );
    for( i = 1; i <= size; ++i ) {
        if( i > 9 ) {
            printf( "%d ", i % 10 );
        } else {
            printf( "%d ", i );
        }
    }
    printf( "\n" );

    printf( "     " );
    for( i = 0; i < size; ++i ) {
        printf( "- " );
    }
    printf( "\n" );
    for( i = 0; i < size; ++i ) {
        printf( "%c  |", alphabet( i+1 ) );
        for( j = 0; j < size; ++j ) {
            if( board[i][j] == 1 ) {
                printf( " X");
            } else if( board[i][j] == 2 ) {
                printf( " O");
            } else {
                printf( "  ");
            }
        }
        printf( " |\n" );
    }
    printf( "     " );
    for( i = 0; i < size; ++i ) {
        printf( "- ");
    }
    printf( "\n" );
}

int read( void )
{
    int size;

    printf( "Zadejte velikost pole: " );
    if( scanf( "%d", &size ) != 1 || size > 26 ) {
        printf( "Nespravny vstup.\n" );
        return 0;
    }

    return size;
}

int player( int board[][26], int sym )
{
    char xc;
    char chs;
    int ret;
    int x, y;

    if( sym == 1) {
        chs = 'X';
    } else {
        chs = 'O';
    }

    printf( "Hrac s %c je na rade.\n", chs);
    printf( "Zadej souradnice tveho tahu: " );
    ret = scanf( " %c %d", &xc, &y );

    if( ret == EOF || ret != 2 ) {
        return 0;
    }

    x = number( xc );

    --x; --y;

    board[x][y] = sym;

    return 1;
}

int main(void)
{
    int  board[26][26];
    int ret;
    int size;


    if( (size = read()) == 0 ) return 1;

    prepareBoard( board, size );

    printBoard( board, size );

    do {
        ret = player( board, 1 );

        printBoard( board, size );

        ret = player( board, 2 );

        printBoard( board, size );
    } while( ret );

    return 0;
}
