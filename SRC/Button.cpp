#include "mbed.h"
#include "Constants.h"
#include "Button.h"

extern things_t myData;
DigitalIn userButton(PUSH_BUTTON);
void readButtonState() {
    /* set stuff up */
    bool lastSwitchState = userButton;
    bool pressed = false;
    while(true){ /* loop forever */
        ThisThread::sleep_for(50ms);
        if (userButton == true) {
            pressed = true;
        }
        if (userButton == false && pressed == true) {
            myData.buttonState = !myData.buttonState;
            pressed = false;
        }
    }
}