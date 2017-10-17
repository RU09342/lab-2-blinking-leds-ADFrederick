
#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= 0x03;


    int toggleLed2 = 0;
    while(1) {
        volatile unsigned int i;
        P1OUT ^= 0x01;// Toggle P1.0 using exclusive-OR

        if(toggleLed2 == 5){
            P1OUT ^= 0x02;
            toggleLed2 = 0;
        }
        toggleLed2 = toggleLed2 + 1;
        __delay_cycles(100000);
    }


}
