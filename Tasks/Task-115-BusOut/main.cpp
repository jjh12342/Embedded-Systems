#include "mbed.h"
#include "uop_msb.h"
#define WAIT_TIME_MS 1000 


// DigitalOut redLED(PC_2,1);
// DigitalOut yellowLED(PC_3,1);
// DigitalOut greenLED(PC_6,1);

//BusOut lights(PC_2, PC_3, PC_6);
BusInOut lights(PC_2, PC_3, PC_6, PC_7, PC_8, PC_9);

int main()
{
    lights.output();
    lights[3].mode(PinMode::OpenDrainNoPull);
    lights[4].mode(PinMode::OpenDrainNoPull);
    lights[5].mode(PinMode::OpenDrainNoPull);
    //All OFF
    lights = 0b000000;
    while (true)
    {
        int count = 0b111111;
        while (count >= 0) 
        {
            printf("count = %d\n", count);
            lights = count ^ 0b111000;
            wait_us(1000000);

            count = count - 1;
        }
    }
}