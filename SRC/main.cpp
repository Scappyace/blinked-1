/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "stdio.h"
#include "Constants.h"
#include "tempsence.h"
#include "lightlevel.h"
#include "Button.h"

// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);
DigitalOut Green(GreenLED);

int main()
{
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        float temperature = readTemp();
        printf("The temperature is: %2.1fC\n", temperature);
        float lightLevel = readLightLevel();
        printf("The light level is: %2.1f%c\n", lightLevel, '%');
        printf("button is %s\n", readButtonState()?"Pressed":"Not Pressed");
        if (readButtonState() ==true) Green = true;
        else Green = false;
    }
}