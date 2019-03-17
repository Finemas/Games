/*
 * Created by Jan Fineas Provaznik on 2019-01-05.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define LEN 50

typedef struct {
    int num;
    char * ind;
} VALUE ;

int randomNumber( int range );
char ** scanPhrase( char ** phrases, int * p_range );
void scanValue( VALUE * array );
void printDice( int value );
char ** delNewlines( char ** phrases, int * p_range );
void updatePhrases( char * newPhrases, char ** phrases, int * p_range );
void negAns( VALUE * array, int * p_value, int * p_fake, int * p_player, int * p_comp );
void positvAns( VALUE * array, char ** phrases, char * newPhrase, int * p_value, int * p_fakeValue, int * p_newValue, int * p_range, int * p_fake, int * p_player, int * p_comp );
void setValue( int * p_value, int * p_phrase, int * p_fake, int * p_range );
void freeAll( char ** phrases );
void end( char ** phrases, char * newPhrase, char * answer, int player, int comp );
void compTurn( VALUE * array, int * p_value, char ** phrases, int * p_phrase, int * p_fake, int * p_fakeValue, int * p_range );
void readPhrase( char * newPhrase, char ** phrases, int * p_range );

void printDice( int value )
{
    switch(value) {
        case 0:
            printf( "  *\t  \n"
                    " *\t * \n"
                    "*\t    \n" );
            break;
        case 1:
            printf( "  *\t  \n"
                    " *\t* *\n"
                    "*\t    \n" );
            break;
        case 2:
            printf( "* *\t   \n"
                    "   \t * \n"
                    "* *\t   \n" );
            break;
        case 3:
            printf( "* *\t   \n"
                    "   \t* *\n"
                    "* *\t   \n" );
            break;
        case 4:
            printf( "* *\t  *\n"
                    "   \t * \n"
                    "* *\t*  \n" );
            break;
        case 5:
            printf( "* *\t   \n"
                    " * \t * \n"
                    "* *\t   \n" );
            break;
        case 6:
            printf( "* *\t   \n"
                    " * \t* *\n"
                    "* *\t   \n" );
            break;
        case 7:
            printf( "* *\t  *\n"
                    " * \t * \n"
                    "* *\t*  \n" );
            break;
        case 8:
            printf( "* *\t* *\n"
                    " * \t   \n"
                    "* *\t* *\n" );
            break;
        case 9:
            printf( "* *\t   \n"
                    "* *\t * \n"
                    "* *\t   \n" );
            break;
        case 10:
            printf( "* *\t   \n"
                    "* *\t* *\n"
                    "* *\t   \n" );
            break;
        case 11:
            printf( "* *\t  *\n"
                    "* *\t * \n"
                    "* *\t*  \n" );
            break;
        case 12:
            printf( "* *\t* *\n"
                    "* *\t   \n"
                    "* *\t* *\n" );
            break;
        case 13:
            printf( "* *\t* *\n"
                    "* *\t * \n"
                    "* *\t* *\n" );
            break;
        case 14:
            printf( "   \t   \n"
                    " * \t * \n"
                    "   \t   \n" );
            break;
        case 15:
            printf( "   \t   \n"
                    "* *\t* *\n"
                    "   \t   \n" );
            break;
        case 16:
            printf( "  *\t  *\n"
                    " * \t * \n"
                    "*  \t*  \n" );
            break;
        case 17:
            printf( "* *\t* *\n"
                    "   \t   \n"
                    "* *\t* *\n" );
            break;
        case 18:
            printf( "* *\t* *\n"
                    " * \t * \n"
                    "* *\t* *\n" );
            break;
        case 19:
            printf( "* *\t* *\n"
                    "* *\t* *\n"
                    "* *\t* *\n" );
            break;
        case 20:
            printf( "   \t   \n"
                    "* *\t * \n"
                    "   \t   \n" );
            break;
    }
}

void setValue( int * p_value, int * p_phrase, int * p_fake, int * p_range )
{
    int value = *p_value;
    int phrase = *p_phrase;
    int fake = *p_fake;

    value = randomNumber( 21 );
    phrase = randomNumber( *p_range );
    fake = randomNumber( 2 );

    *p_value = value;
    *p_phrase = phrase;
    *p_fake = fake;
}

int randomNumber( int range )
{
    srand(time(NULL));
    int random = rand() % range;

    return random;
}

//void updatePhrases( char * newPhrases, char ** phrases, int * p_range )
{
    int range = *p_range;
    int i;
    int write = 1;
    FILE * fp = fopen( "data.txt", "a" );

    for( i = 0; i < range; ++i ) {
        printf( "%s", phrases[i] );
        if( strcmp( newPhrases, phrases[i] ) == 0 ) {
            write = 0;
            printf( "Nebudu zapisovat\n" );
        }
    }

    if( write ) {
        printf( "Zapisuju -%s", newPhrases );
        fprintf( fp, "%s", newPhrases );
    }

    fclose( fp );
}

void scanValue( VALUE * array )
{
    array[0].num = 31;
    array[1].num = 32;
    array[2].num = 41;
    array[3].num = 42;
    array[4].num = 43;
    array[5].num = 51;
    array[6].num = 52;
    array[7].num = 53;
    array[8].num = 54;
    array[9].num = 61;
    array[10].num = 62;
    array[11].num = 63;
    array[12].num = 64;
    array[13].num = 65;
    array[14].ind = "indiani";
    array[15].ind = "dva indiani";
    array[16].ind = "tri indiani";
    array[17].ind = "ctyri indiani";
    array[18].ind = "pet indianu";
    array[19].ind = "sest indianu";
    array[20].ind = "machacka";
}

char ** scanPhrase( char ** phrases, int * p_range )
{
    int range = *p_range;
    FILE * fp = fopen( "data.txt", "r" );

    while( !feof(fp) ) {
        //printf( "zapis do %d\n", range );
        phrases[range] = (char*) calloc ( LEN, sizeof(*phrases) );
        fgets( phrases[range], LEN, fp );
        //printf( "%d.range  %s", range, phrases[range] );
        if( range == LEN ) {
            phrases = realloc( phrases, 10 * sizeof(*phrases) );
        }
        ++range; // range bude ukazovat pocet nactenych frazich
    }

    while( phrases[range-1][0] == '\0' || phrases[range-1][0] == '\n' ) {
        range--;
    }

    fclose( fp );

    delNewlines( phrases, &range );

    *p_range = range;
    return phrases;
}

char ** delNewlines( char ** phrases, int * p_range )
{
    int i, j;

    int range = *p_range;

    for( i = 0; i < range; ++i ) {
        for( j = 0; j < LEN; ++j ) {
            if( phrases[i][j] == '\n' ) {
                phrases[i][j] = '\0';
            }
        }
    }

    return phrases;
}

void negAns( VALUE * array, int * p_value, int * p_fake, int * p_player, int * p_comp )
{
    int value = *p_value;
    int fake = *p_fake;

    int player = *p_player;
    int comp = *p_comp;

    printf( "Neveris?\n" );
    sleep(1);

    printDice( value );

    if( value <= 13) {
        printf("Hodnota byla %d.\n", array[value].num);
    } else {
        printf("Hodnota byla %s.\n", array[value].ind);
    }

    if( fake == 1 ) {
        sleep(1);
        printf( "Mas pravdu, lhal jsem.\n");
        sleep(1);
        printf( "Ziskavas jeden bod.\n" );
        ++player;
    } else if( fake == 0 ) {
        sleep(1);
        printf( "Nene, nelhal jsem.\n" );
        sleep(1);
        printf( "Ziskavam bod ja.\n" );
        ++comp;
    } else {
        printf( "\nCHYBA: nefunguje fake-mode!.\n");
    }

    *p_player = player;
    *p_comp = comp;
}

void positvAns( VALUE * array, char ** phrases, char * newPhrase, int * p_value, int * p_fakeValue, int * p_newValue, int * p_range, int * p_fake, int * p_player, int * p_comp )
{
    int range = *p_range;
    int value = *p_value;
    int fakeValue = *p_fakeValue;
    int newValue = *p_newValue;
    int fake = *p_fake;
    //int player = *p_player;
    //int comp = *p_comp;
    //int range = *p_range;
    //int answer = 0;

    if( fake == 0 ) {
        if( value <= 13 ) {
            printf("Musis prekonat %d.\n", array[value].num);
        } else if( value > 13 && value <= 20 ) {
            printf("Musis prekonat %s.\n", array[value].ind);
        } else {
            printf( "\nCHYBA: spatna hodnota value!\n" );
            exit(1);
        }

    } else if( fake == 1 ){

        if( fakeValue <= 13 ) {
            printf("Musis prekonat %d.\n", array[fakeValue].num);
        } else if( fakeValue > 13 && fakeValue <= 20 ) {
            printf("Musis prekonat %s.\n", array[fakeValue].ind);
        } else {
            printf( "\nCHYBA: spatna hodnota fakeValue!\n" );
            exit(1);
        }

    } else {
        printf( "\nCHYBA: spatne se predal fake!\n");
        exit(1);
    }

    printf( "Hazis kostkami." );
    sleep(1);
    printf( "...\n" );

    newValue = randomNumber( 21 );
    sleep(1);

    printDice( newValue );

    sleep(2);

    readPhrase( newPhrase, phrases, &range );
}

void end( char ** phrases, char * newPhrase, char * answer, int player, int comp )
{
    printf( "\n" );

    if( player > comp ) {
        printf( "Gratuluji vyhral si! %d:%d\n", player, comp );
        sleep(1);
        printf( "Tak snad priste znovu ;)\n");
    } else if ( player == comp ) {
        printf( "Remiza %d:%d\n", player, comp );
        sleep(1);
        printf( "Prijd priste, at se rozhodne =) \n" );
    } else {
        printf( "Bohuzel, dnes si nevyhral...\n");
        sleep(1);
        printf( "Zkus to priste, dame odvetu ;)\n");
    }

    freeAll( phrases );
    free( newPhrase );
    free( answer );
}

void freeAll( char ** phrases )
{
    int i = 0;

    while( phrases[i] ) {
        free( phrases[i] );
        ++i;
    }

    free( phrases );
}

void readPhrase( char * newPhrase, char ** phrases, int * p_range )
{
    int range = *p_range;
    int i = 0;
    int value = 0;

    printf( "Rekni co jsi hodil.\n" );
    fgets( newPhrase, LEN, stdin );
    //printf( "%s", newPhrase );

    //nacteni hodnotu intu ze stringu
    while( newPhrase[i] != '\n' ) {
        if( newPhrase[i] >= 48 && newPhrase[i] <= 57 ) {
            value = ((newPhrase[i]) - 48) * 10; //prevadeni ascii hodnoty na cislo
            newPhrase[i] = '#';
            value += (newPhrase[++i]) - 48;
            newPhrase[i] = '#';
            printf( "%d\n", value );
            break;
        }
        ++i;
    }

    while( 1 ) {
        if( newPhrase[i] == '?' ) {
            newPhrase[i] = '\0';
            break;
        }
        ++i;
    }

    printf( "%s\n", newPhrase );

    updatePhrases( newPhrase, phrases, &range );
}

int main()
{
    VALUE array[21];
    char * answer = (char*) malloc ( 10 * sizeof(*answer) );
    char ** phrases = (char**) calloc ( 10, sizeof(*phrases) );
    char * newPhrase = (char*) calloc ( 100, sizeof(*newPhrase) );
    //controller
    //int control = 0;

    //random number
    //int phrase = 0, value = 0, fake = 0;
    //int fakeValue = 0;
    //int newValue = 0;

    //counter
    int comp = 0;
    int player = 0;
    //int round = 1;
    int range = 0;

    int i = 0;
    int j = 0;
    int say = 0;

    scanValue( array );
    phrases = scanPhrase( phrases, &range );

    printf( "Rikej.\n" );
    fgets( newPhrase, 100, stdin );

    while( i < LEN ) {
        while( newPhrase[i] == array[14].ind[j] ) {
            ++i;
            ++j;
            if( j == 7 ) {
                array[14].ind[j] = '#';
                say = 14;
            }
        }
        while( newPhrase[i] == array[15].ind[j] ) {
            ++i;
            ++j;
            if( j == 11 ) {
                array[15].ind[j] = '#';
                say = 15;
            }
        }
        while( newPhrase[i] == array[16].ind[j] ) {
            ++i;
            ++j;
            if( j == 1 ) {
                array[16].ind[j] = '#';
                say = 16;
            }
        }
        while( newPhrase[i] == array[17].ind[j] ) {
            ++i;
            ++j;
            if( j == 13 ) {
                array[17].ind[j] = '#';
                say = 17;
            }
        }
        while( newPhrase[i] == array[18].ind[j] ) {
            ++i;
            ++j;
            if( j == 11 ) {
                array[18].ind[j] = '#';
                say = 18;
            }
        }
        while( newPhrase[i] == array[19].ind[j] ) {
            ++i;
            ++j;
            if( j == 12 ) {
                array[19].ind[j] = '#';
                say = 19;
            }
        }
        while( newPhrase[i] == array[20].ind[j] ) {
            ++i;
            ++j;
            if( j == 8 ) {
                array[20].ind[j] = '#';
                say = 20;
            }
        }
        ++i;
    }

    printf( "String obsahuje hodnotu %s.\n", array[say].ind );

    printf( "%s", array[say].ind );

    /* array[14].ind = "indiani";
    array[15].ind = "dva indiani";
    array[16].ind = "tri indiani";
    array[17].ind = "ctyri indiani";
    array[18].ind = "pet indianu";
    array[19].ind = "sest indianu";
    array[20].ind = "machacka"; */

    end( phrases, newPhrase, answer, player, comp );
}
