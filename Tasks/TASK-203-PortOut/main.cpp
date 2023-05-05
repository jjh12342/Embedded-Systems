#include "mbed.h"

// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

//define the leds on the bored
#define  TRAF_LED_1 PB_0
#define  TRAF_LED_2 PB_7
#define  TRAF_LED_3 PB_14

#define LEDMASK 0b0000000001001100
// Objects
//BusOut leds(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN);
PortOut leds(PortC, LEDMASK);
PortOut onBLeds(PortB, LEDMASK);

int main()
{
    while (true) {
        leds = 0;   //Binary 000
        onBLeds =0;
        wait_us(500000);
        leds = 0xFF;
        onBLeds = 0xFF ;   //Binary 11111111
        wait_us(500000);    
    }
}




