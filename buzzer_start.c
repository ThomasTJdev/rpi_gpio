#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

/* gcc -Wall filein.c -o fileout -lwiringPi */
/* GPIO + 3,3v */

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        printf( "usage: %s pinnumber", argv[0] );
    }
    else
    {
        if(wiringPiSetup() < 0)return 1;
        int BUZ = atoi(argv[1]);
        pinMode (BUZ,OUTPUT);
        digitalWrite(BUZ, 1);
    }
}
