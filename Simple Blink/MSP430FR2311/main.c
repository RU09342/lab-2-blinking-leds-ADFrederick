#include <msp430.h>     // Header file containing pin assignments

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // enable GPIO usage

    P2DIR = 0x01;
    P2OUT = 0x01;

    while (1){
        P2OUT ^= 0x01;
        __delay_cycles(50000);
       }

}
