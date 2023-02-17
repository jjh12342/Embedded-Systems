#include "uop_msb.h"
using namespace uop_msb;

// main() runs in its own thread in the OS
DigitalOut redLED(PC_2);
DigitalOut greenLED(PC_6);
DigitalOut amberLED(PC_3);

LCD_16X2_DISPLAY lcd;

int main()
{
    lcd.cls();
    lcd.puts("TASK - 114 Joe");
    while (true) {
        redLED = 1;
        wait_us(2000000);
        amberLED = 1;
        wait_us(2000000);
        redLED = 0;
        amberLED = 0;
        greenLED = 1;
        wait_us(8000000);
        greenLED = 0;
        int count = 0;
        while (count < 4) {
            amberLED = 1;
            wait_us(250000);
            amberLED = 0;
            wait_us(250000);   
            count = count + 1;     
        }
    }
}

