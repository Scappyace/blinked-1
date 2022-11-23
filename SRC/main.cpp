/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0

#include "mbed.h"

// Initialise the digital pin LED1 as an output
DigitalOut led(LED1);
DigitalOut vdd(thermPower);
DigitalOut gnd(thermGround);
AnalogIn temperatureVoltage( thermOut );

// prototype for function calls
float readTemp();

int main()
{
    while (true) {
        led = !led;
        ThisThread::sleep_for(BLINKING_RATE);
        gnd = false;
        vdd = true;
        float temperature = readTemp();
        vdd = false;

        printf("The temperature is: %2.1fC\n", temperature);
    }
}
float readTemp() {
    float refVoltage = temperatureVoltage.read() * 2.4; // Range of ADC 0->2*Vref
    float refCurrent = refVoltage  / 10000.0; // 10k Reference Resistor
    float thermVoltage = 3.3 - refVoltage;    // Assume supply voltage is 3.3v
    float thermResistance = thermVoltage / refCurrent; 
    float logrT = (float32_t)log((float64_t)thermResistance);
    /* Calculate temperature from the resistance of thermistor using Steinhart-Hart Equation */
    float stEqn = (float32_t)((A_COEFF) + ((B_COEFF) * logrT) + 
                             ((C_COEFF) * pow((float64)logrT, (float32)3)));
    float temperatureC = (float32_t)(((1.0 / stEqn) + ABSOLUTE_ZERO)  + 0.05);
    return temperatureC;
}

