/*  Potentiometer-Read-Template
*   Read a potentiometer, pot1 frome an analogue input, using the AnalogIn class. 
*   The pot1 value is used to control the 4 LEDs on the output bus.
*   When the pot value is <50% the first 2 LEDs will be ON
*   When the pot value is >50% the last 2 LEDs will be ON
*
*   Board: NUCLEO L476RG
*   Author: James Chandler 2021
*/

#include "mbed.h"

//define output pins
BusOut leds_bus(PC_0, PC_1, PB_0, PA_4); // Create BusOut Object called led_bus and assign bus pins (LSB, ....., MSB)

//define analugue input to read potentiometer voltage
AnalogIn pot1(PA_5);

//declare initialisation function
void init_leds();

//declare variables
int cntl_val = 0;       // Create & initialise int variable to control to output state of the bus 

int main(){
    init_leds();               //initalise leds

    while(1){

       cntl_val = pot1.read_u16()/32768;
              
       if(cntl_val){leds_bus.write(3);}
        else{leds_bus.write(12);}
        
        ThisThread::sleep_for(100ms);
    }
}

// Implement initialisation function
void init_leds(){
    leds_bus.write(0);   //turn off leds by default
}
