/* this function reads the thermistor voltage and returns in celsius using 
steinhart hart conversion from the thermistor resistance
*/
#include "mbed.h"
#include "constants.h"
#include "lightlevel.h"


AnalogIN LightLevelVoltage ( lightout );

float lightLevel() {
        //Apply Power to thermistor

        //read the light level dependant resistor voltage
        float lightLevel = lightLevelVoltage.read() * 100; /range of ACD .read 0->1

        return lightLevel;
}