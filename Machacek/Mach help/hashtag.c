#include <stdio.h>

int main()
{
    char answer[50] = "Myslis, ze mam ##" ;
    int value = 53;
    int i = 0;
    int j = 0;

    while( i != 50 ) {
        if( answer[i] == '#' ) {
            answer[i] = ;
            ++value;
        }
        ++i;
    }

    printf( "%s", answer );

    /*
    Myslis, ze mam ##
    Veris mi, ze mam ##
    Co takhle ##
    Mam, ci nemam ##
    Veris mi ##
     */

}
