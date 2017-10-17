#include <msp430.h>     // Header file containing pin assignments

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    
    P1DIR = 0x01;
    P1OUT = 0x01;

    while (1){
        P1OUT ^= 0x01;
        __delay_cycles(50000);
       }

}
