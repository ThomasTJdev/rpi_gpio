#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

/* gcc -Wall filein.c -o fileout -lwiringPi */
/* GPIO + GND */

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        printf( "usage: %s pinnumber", argv[0] );
    }
    else
    {
        if(wiringPiSetup() < 0)return 1;
        int LED = atoi(argv[1]);
        pinMode (LED,OUTPUT);
        digitalWrite(LED, 1);
    }
}
