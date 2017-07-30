#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
/* gcc -Wall filein.c -o fileout -lwiringPi */
/* GPIO + GND + 5v */

FILE *fp;

int main(int argc, char *argv[])
{
    if ( argc != 2 )
    {
        printf( "usage: %s pinnumber", argv[0] );
    }
    else
    {
        if(wiringPiSetup() < 0)return 1;
        int PIR = atoi(argv[1]);
        int checker = 0;
        remove("tmp/pir.txt");
        pinMode(PIR, INPUT);
        while(1)
        {
            if(digitalRead(PIR))
            {
                printf("Motion Detected!\n");
                checker++;
                printf("%d", &checker);
                fp = fopen("tmp/pir.txt", "a");
                fputs("1", fp);
                fclose(fp);
                delay(400);
            }
            else
            {
                if(checker >= 3)
                {
                    printf("Checker 3");
                    delay(60000);
                    fp = fopen("tmp/pir.txt", "w+");
                    fputs("", fp);
                    fclose(fp);
                    checker = 0;
                }
                checker = 0;
            }
            delay(100);
        }
    }
}
