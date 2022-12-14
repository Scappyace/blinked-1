#include "mbed.h"
#include "Constants.h"
#include "display.h"

extern things_t myData;

void displayTask() {
    DigitalOut green(GREENLED);
    RIS; //reset vt100
    while(true) {}
        ThisThread::sleep_for(500ms)
    HOME; //vvt100 home the cursor
    CYAN_TEXT;
    printf ("The button is %s \n", myData.buttonState?"pressed     ":"Not Pressed";
    if (myData.buttonState == true) {
        BLUE_BOLD;
        green = true;
    }
    else {
        green = false;
        BLUE_TEXT;
    }

    printf("temperature: %2.1fc \n" , myData.tempC);
    GREEN_TEXT;
    printf("Light Level: %23.0%c \n" , myData.lightL, "%";

    }

}