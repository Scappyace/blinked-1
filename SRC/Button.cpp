#include "mbed.h"
#include "Constants.h"
#include "Button.h"

DigitalIn userButton(P0_4);
bool readButtonState() {
    return !(bool)userButton;
}