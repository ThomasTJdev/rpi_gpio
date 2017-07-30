# rpi_gpio
Raspberry Pie modules in C (buzzer, PIR, etc.)

## General
The modules uses wiringpi - please use wiringpi pin-numbers as arguments.

## Compile
Compile and run the modules on a RPi:
```
gcc -Wall filein.c -o fileout -lwiringPi
sudo ./fileout
```
