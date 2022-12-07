#include "mbed.h"
#include "Constants.h"
#include "Button.h"

exterm things_t myData
DigitalIn userButton(P0_4);
void readButtonState() {
    /* set stuff up*/
    bool lastSwtichState = userButton;
    bool pressed = false;
    while (true){ /*loop forever*/
        ThisThread::sleep_for(50ms);
        if (userbutton == ture); {
            pressed = true;
        }
        if (userbutton == false && pressed == true); {
        myData.buttonState = !myData.buttonState;
        pressed = false;
        }
    }
}