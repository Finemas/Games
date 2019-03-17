/*
 * Created by Jan Fineas Provaznik on 2019-01-05.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define LEN 100

typedef struct {
    int num;
    char * ind;
} VALUE ;

void printDice( int value )
{
    //printf( "\n" );
    switch(value) {
        case 0:
            printf( "    *\t  \n"
                    "   *\t * \n"
                    "  *\t    \n" );
            break;

        case 1:
            printf( "    *\t  \n"
                    "   *\t* *\n"
                    "  *\t    \n" );
            break;

        case 2:
            printf( "  * *\t   \n"
                    "     \t * \n"
                    "  * *\t   \n" );
            break;

        case 3:
            printf( "  * *\t   \n"
                    "     \t* *\n"
                    "  * *\t   \n" );
            break;

        case 4:
            printf( "  * *\t  *\n"
                    "     \t * \n"
                    "  * *\t*  \n" );
            break;

        case 5:
            printf( "  * *\t   \n"
                    "   * \t * \n"
                    "  * *\t   \n" );
            break;

        case 6:
            printf( "  * *\t   \n"
                    "   * \t* *\n"
                    "  * *\t   \n" );
            break;

        case 7:
            printf( "  * *\t  *\n"
                    "   * \t * \n"
                    "  * *\t*  \n" );
            break;

        case 8:
            printf( "  * *\t* *\n"
                    "   * \t   \n"
                    "  * *\t* *\n" );
            break;

        case 9:
            printf( "  * *\t   \n"
                    "  * *\t * \n"
                    "  * *\t   \n" );
            break;

        case 10:
            printf( "  * *\t   \n"
                    "  * *\t* *\n"
                    "  * *\t   \n" );
            break;

        case 11:
            printf( "  * *\t  *\n"
                    "  * *\t * \n"
                    "  * *\t*  \n" );
            break;

        case 12:
            printf( "  * *\t* *\n"
                    "  * *\t   \n"
                    "  * *\t* *\n" );
            break;

        case 13:
            printf( "  * *\t* *\n"
                    "  * *\t * \n"
                    "  * *\t* *\n" );
            break;

        case 14:
            printf( "     \t   \n"
                    "   * \t * \n"
                    "     \t   \n" );
            break;

        case 15:
            printf( "     \t   \n"
                    "  * *\t* *\n"
                    "     \t   \n" );
            break;

        case 16:
            printf( "    *\t  *\n"
                    "   * \t * \n"
                    "  *  \t*  \n" );
            break;

        case 17:
            printf( "  * *\t* *\n"
                    "     \t   \n"
                    "  * *\t* *\n" );
            break;

        case 18:
            printf( "  * *\t* *\n"
                    "   * \t * \n"
                    "  * *\t* *\n" );
            break;

        case 19:
            printf( "  * *\t* *\n"
                    "  * *\t* *\n"
                    "  * *\t* *\n" );
            break;

        case 20:
            printf( "     \t   \n"
                    "  * *\t * \n"
                    "     \t   \n" );
            break;

        default:
            printf( "\nCHYBA - PRINTDICE: spatna hodnota Value ve funkci!\n" );
            exit(1);
    }
    //printf( "\n" );
}

void scanVauleFromFile( VALUE * array )
{
    array[0].num = 31;
    array[0].ind = NULL;
    array[1].num = 32;
    array[1].ind = NULL;
    array[2].num = 41;
    array[2].ind = NULL;
    array[3].num = 42;
    array[3].ind = NULL;
    array[4].num = 43;
    array[4].ind = NULL;
    array[5].num = 51;
    array[5].ind = NULL;
    array[6].num = 52;
    array[6].ind = NULL;
    array[7].num = 53;
    array[7].ind = NULL;
    array[8].num = 54;
    array[8].ind = NULL;
    array[9].num = 61;
    array[9].ind = NULL;
    array[10].num = 62;
    array[10].ind = NULL;
    array[11].num = 63;
    array[11].ind = NULL;
    array[12].num = 64;
    array[12].ind = NULL;
    array[13].num = 65;
    array[13].ind = NULL;
    array[14].num = 0;
    array[14].ind = "indiani";
    array[15].num = 0;
    array[15].ind = "dva indiani";
    array[16].num = 0;
    array[16].ind = "tri indiani";
    array[17].num = 0;
    array[17].ind = "ctyri indiani";
    array[18].num = 0;
    array[18].ind = "pet indianu";
    array[19].num = 0;
    array[19].ind = "sest indianu";
    array[20].num = 0;
    array[20].ind = "machacka";
}

int randomNumber( int range )
{
    srand(time(NULL));
    int random = rand() % range;

    return random;
}

void setValue( int * p_value, int * p_phrase, int * p_fake, int range )
{
    int value = *p_value;
    int phrase = *p_phrase;
    int fake = *p_fake;

    value = randomNumber( 21 );
    phrase = randomNumber( range );
    fake = randomNumber( 2 );

    *p_value = value;
    *p_phrase = phrase;
    *p_fake = fake;
}

char ** delNewlines( char ** phrases, int range )
{
    int i, j;

    for( i = 0; i < range; ++i ) {
        for( j = 0; j < LEN; ++j ) {
            if( phrases[i][j] == '\n' ) {
                phrases[i][j] = '\0';
            }
        }
    }

    return phrases;
}

char ** scanPhraseFromFile( char ** phrases, int * p_range )
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

    delNewlines( phrases, range );

    *p_range = range;
    return phrases;
}

void updatePhrases( char * newPhrases, char ** phrases, int range )
{
    int i;
    int write = 1;
    FILE * fp = fopen( "data.txt", "a" );

    for( i = 0; i < range; ++i ) {
        //printf( "%s", phrases[i] );
        if( strcmp( newPhrases, phrases[i] ) == 0 ) {
            write = 0;
            //printf( "Nebudu zapisovat\n" );
        }
    }

    if( write ) {
        //printf( "Zapisuju -%s", newPhrases );
        fprintf( fp, "%s", newPhrases );
    }

    fclose( fp );
}

int findValueInt( char * newPhrase, int * p_scanValueInt )
{
    int scanValueInt = *p_scanValueInt;
    int i = 0;

    while (newPhrase[i] != '\n') {
        if (newPhrase[i] >= 48 && newPhrase[i] <= 57) {
            scanValueInt = ((newPhrase[i]) - 48) * 10; //prevadeni ascii hodnoty na cislo
            //newPhrase[i] = '#';
            scanValueInt += (newPhrase[++i]) - 48;
            //newPhrase[i] = '#';
            //printf("String obsahuje hodnotu %d\n", scanValueInt);

            *p_scanValueInt = scanValueInt;
            return 0;
        }
        ++i;
    }

    return 1;
}

int findValueChar( VALUE * array, char * newPhrase, char * scanValueChar )
{
    int i = 0, j = 0;

    while (i < LEN) {
        while( newPhrase[i] == array[14].ind[j] ) {
            ++i;
            ++j;
            if (j == 7) {
                strncpy( scanValueChar, array[14].ind, LEN );
                return 0;
            }
        }
        while( newPhrase[i] == array[15].ind[j] ) {
            ++i;
            ++j;
            if (j == 11) {
                strncpy( scanValueChar, array[15].ind, LEN );
                return 0;
            }
        }
        while( newPhrase[i] == array[16].ind[j] ) {
            ++i;
            ++j;
            if (j == 1) {
                strncpy( scanValueChar, array[16].ind, LEN );
                return 0;
            }
        }
        while( newPhrase[i] == array[17].ind[j] ) {
            ++i;
            ++j;
            if (j == 13) {
                strncpy( scanValueChar, array[17].ind, LEN );
                return 0;
            }
        }
        while( newPhrase[i] == array[18].ind[j] ) {
            ++i;
            ++j;
            if (j == 11) {
                strncpy( scanValueChar, array[18].ind, LEN );
                return 0;
            }
        }
        while( newPhrase[i] == array[19].ind[j] ) {
            ++i;
            ++j;
            if (j == 12) {
                strncpy( scanValueChar, array[19].ind, LEN );
                return 0;
            }
        }
        while( newPhrase[i] == array[20].ind[j] ) {
            ++i;
            ++j;
            if (j == 8) {
                strncpy( scanValueChar, array[20].ind, LEN );
                return 0;
            }
        }
        ++i;
    }

    return 1;
}

int findIndex( VALUE * array, char * scanValueChar, int scanValueInt )
{
    int index = 0;

    do{
        if( scanValueInt == array[index].num ) {
            return index;
        }
        ++index;
    } while( index != 14  );

    while( index != 21 )  {
        if( strcmp( scanValueChar, array[index].ind ) == 0 ) {
            return index;
        }
        ++index;
    }

    printf( "CHYBA - FINDINDEX: spatne nactena hodnota ze stringu!.\n" );
    return 2;
}

void readPhrase( VALUE * array, char * newPhrase, char * scanValueChar, int * p_scanValueInt, int * p_index )
{
    int scanValueInt = *p_scanValueInt;
    int index = *p_index;
    int intchar = 1;

    while( intchar ) {
        printf( "Co jsi hodil?\n" );
        fgets( newPhrase, LEN, stdin );

        intchar = findValueInt( newPhrase, &scanValueInt );
        
        if( intchar ) {
            intchar = findValueChar( array, newPhrase, scanValueChar );
        }

    }

    int i = 0;
    while( 1 ) {
        if( newPhrase[i] == '?' ) {
            newPhrase[i] = '\0';
            break;
        }
        ++i;
    }

    //updatePhrases( newPhrase, phrases, range );

    index = findIndex( array, scanValueChar, scanValueInt );

    *p_index = index;
    *p_scanValueInt = scanValueInt;
}

void compTurn( VALUE * array, char ** phrases, int * p_phrase, int * p_value, int * p_newValue, int * p_fake, int * p_fakeValue, int range )
{
    int phrase = *p_phrase;
    int value = *p_value;
    int newValue = *p_newValue;
    int fake = *p_fake;
    int fakeValue = *p_fakeValue;

    setValue( &value, &phrase, &fake, range );

    if( value > newValue ) {
        if (fake == 0) { /* Nelzu */

            if (value <= 13) {
                printf("%s %d?\n", phrases[phrase], array[value].num);
            } else if (value > 13 && value <= 20) {
                printf("%s %s?\n", phrases[phrase], array[value].ind);
            } else {
                printf("\nCHYBA - COMPTURN: spatna hodnota value!\n");
                exit(1);
            }

        } else if (fake == 1) { /* Lze */

            do {
                fakeValue = randomNumber(21);
                sleep(1);
            } while( fakeValue == value );

            fakeValue = randomNumber(21);

            if (fakeValue <= 13) {
                printf("%s %d?\n", phrases[phrase], array[fakeValue].num);
            } else if (fakeValue > 13 && fakeValue <= 20) {
                printf("%s %s?\n", phrases[phrase], array[fakeValue].ind);
            } else {
                printf("\nCHYBA - COMPTURN: spatna hodnota fakeValue!\n");
                exit(1);
            }

        } else {
            printf("\nCHYBA - COMPTURN: nefunguje fake-mode!\n");
            exit(1);
        }
    } else {

        do {
            fakeValue = randomNumber(21);
            sleep(1);
        } while( fakeValue <= newValue );

        fakeValue = randomNumber(21);

        if (fakeValue <= 13) {
            printf("%s %d?\n", phrases[phrase], array[fakeValue].num);
        } else if (fakeValue > 13 && fakeValue <= 20) {
            printf("%s %s?\n", phrases[phrase], array[fakeValue].ind);
        } else {
            printf("\nCHYBA - COMPTURN: spatna hodnota fakeValue!\n");
            exit(1);
        }

    }

    *p_value = value;
    *p_phrase = phrase;
    *p_fake = fake;
    *p_fakeValue = fakeValue;
}

int compAns( VALUE * array, char * scanValueChar, int scanValueInt, int newValue, int index, int * p_player , int * p_comp )
{
    int player = *p_player;
    int comp = *p_comp;
    int answer = 0;

    answer = randomNumber(2);

    if (answer == 0) {
        printf("Neverim ti!\n");
        sleep(1);
        printf("Ukaz co jsi hodil.\n");
        sleep(1);

        printDice(newValue);

        if(index == newValue) {
            printf("Mel jsi pravdu.\n");
            sleep(1);
            printf("Mas bod.\n");
            ++player;
        } else {
            printf("Lhal si.\n");
            sleep(1);
            printf("Mam bod ja.\n");
            ++comp;
        }

        *p_player = player;
        *p_comp = comp;

        return 0;

    } else {
        printf("Verim ti.\n");

        return 1;
    }

}

void positvAns( VALUE * array, char ** phrases, char * newPhrase, char * scanValueChar, int * p_scanValueInt , int value, int fakeValue, int * p_newValue, int fake, int index, int * p_player, int * p_comp, int * p_end )
{
    int scanValueInt = *p_scanValueInt;
    int newValue = *p_newValue;
    int player = *p_player;
    int comp = *p_comp;
    int end = *p_end;

    if( fake == 0 ) {
        if( value <= 13 ) {
            printf("Musis prekonat %d.\n", array[value].num);
        } else if( value > 13 && value <= 20 ) {
            printf("Musis prekonat %s.\n", array[value].ind);
        } else {
            printf( "\nCHYBA - POSITIVANS: spatna hodnota value!\n" );
            exit(1);
        }

    } else if( fake == 1 ){

        if( fakeValue <= 13 ) {
            printf("Musis prekonat %d.\n", array[fakeValue].num);
        } else if( fakeValue > 13 && fakeValue <= 20 ) {
            printf("Musis prekonat %s.\n", array[fakeValue].ind);
        } else {
            printf( "\nCHYBA - POSITIVANS: spatna hodnota fakeValue!\n" );
            exit(1);
        }

    } else {
        printf( "\nCHYBA - POSITIVANS: spatne se predal fake!\n");
        exit(1);
    }

    printf( "Hazis kostkami." );
    sleep(1);
    printf( "...\n" );

    newValue = randomNumber( 21 );
    if( newValue == value ) {
        newValue = randomNumber( 21 );
    }

    printDice( newValue );

    sleep(2);

    readPhrase( array, newPhrase, scanValueChar, &scanValueInt, &index );

    end = compAns( array, scanValueChar, scanValueInt, newValue, index, &player, &comp );

    if( end == 0 ) {
        newValue = index;
        printf( "Hraju ja.\n" );
    }

    *p_scanValueInt = scanValueInt;
    *p_newValue = newValue;
    *p_player = player;
    *p_comp = comp;
    *p_end = end;
}

void negAns( VALUE * array, int value, int fake, int * p_player, int * p_comp, int * p_end )
{
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
        printf( "\nCHYBA - NEGANS: nefunguje fake-mode!.\n");
    }

    *p_player = player;
    *p_comp = comp;
    *p_end = 0;
}

void freeAll( char ** phrases, char * newPhrase, char * answer, char * scanValueChar )
{
    int i = 0;

    while( phrases[i] ) {
        free( phrases[i] );
        ++i;
    }

    free( phrases );
    free( newPhrase );
    free( answer );
    free( scanValueChar );
}

void bye( char ** phrases, char * newPhrase, char * answer, char * scanValueChar, int player, int comp )
{
    printf( "\n" );

    if( player > comp ) {
        printf( "Gratuluji vyhral si! %d:%d\n", player, comp );
        sleep(1);
        printf( "Tak snad priste znovu ;)\n\n");
    } else if ( player == comp ) {
        printf( "Remiza %d:%d\n", player, comp );
        sleep(1);
        printf( "Prijd priste, at se rozhodne =) \n\n" );
    } else {
        printf( "Bohuzel, dnes si nevyhral...\n");
        sleep(1);
        printf( "Zkus to priste, dame odvetu ;)\n\n");
    }

    freeAll( phrases, newPhrase, answer, scanValueChar );
}

int main()
{
    VALUE array[21];
    char * answer = (char*) calloc ( 5, sizeof(*answer) );
    char ** phrases = (char**) calloc ( LEN, sizeof(*phrases) );
    char * newPhrase = (char*) calloc ( LEN+1, sizeof(*newPhrase) );

    char * scanValueChar = (char*) calloc ( LEN, sizeof(*scanValueChar) );
    int scanValueInt = 0;

    //controller
    int control = 0;
    int end = 1;

    //values
    int phrase = 0, value = 0, fake = 0;
    int fakeValue = 0;
    int newValue = 0;
    int index = 0;

    //counter
    int comp = 0, player = 0;
    int round = 1;
    int range = 0;

    scanVauleFromFile( array );
    phrases = scanPhraseFromFile( phrases, &range );

    readPhrase( array, newPhrase, scanValueChar, &scanValueInt, &index );

    /*printf( "\nJdeme hrát Macháčka!\n" );
    sleep(2);

    while( 1 ) {
        printf("Zacina %d. kolo\n", round);
        sleep(1);
        printf("Skore %d:%d\n", player, comp);
        sleep(2);

        do{
            compTurn( array, phrases, &phrase, &value, &newValue, &fake, &fakeValue, range );

            control = 1;

            do{
                if( scanf( "%s", answer ) == EOF ) {
                    bye( phrases, newPhrase, answer, scanValueChar, player, comp );
                    return 0;
                }

                if( strcmp( answer, "ne" ) == 0 || strcmp( answer, "Ne" ) == 0 ) {
                    negAns( array, value, fake, &player, &comp, &end );
                    control = 0;
                } else if( strcmp( answer, "ano" ) == 0 || strcmp( answer, "Ano" ) == 0 ) {
                    positvAns( array, phrases, newPhrase, scanValueChar, &scanValueInt, value, fakeValue , &newValue, fake, index, &player, &comp, &end );
                    control = 0;
                } else {
                    printf( "Odpoved musi byt ano/ne nebo Ano/Ne.\n" );
                }

            } while( control );

        } while( end );

        printf( "\n" );
        ++round;
    } */

    bye( phrases, newPhrase, answer, scanValueChar, player, comp );

}
