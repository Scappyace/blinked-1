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
#include "display.h"

// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);
things_t myData;
Thread readTempHandle;
Thread lightLevelHandle;
Thread buttonHandle;
Thread displayHandle;

int main()
{
    readTempHandle.start(callback(readTemp));
    lightLevelHandle.start(callback(readLightLevel));
    buttonHandel.start(callback(readButtonState));
    displayhandle.start(callback(displayTask));
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
//        printf("button is %s\n", readButtonState()?"Pressed":"Not Pressed");
//        if (readButtonState() ==true) Green = true;
        else Green = false;
    }
}