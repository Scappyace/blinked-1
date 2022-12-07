#include "mbed.h"
#include "Constants.h"
#include "display.h"

extern things_t myData;

void displayTask() {
    DigitalOut Green(GreenLED);

    while(true){
        printf("The Button is %s\n", myData.buttonState?"Pressed":"Not Pressed");
        if (buttonState() ==true) Green = true;
        else green = false
    }
}