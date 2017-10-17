#include <msp430.h>     // Header file containing pin assignments

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;       // enable GPIO usage
    volatile int i;

    P1DIR = 0x01;				//setting directions of pins
    P2DIR = 0x01;
    P1OUT = 0x01;
    P2OUT = 0x01;

    while(1){
        for(i=0; i<10000; i++) {
                  if(i % 2311 == 0) {
                      P2OUT ^=0x01;
                  }
                  if(i % 5529 == 0) {
                      P1OUT ^= 0x01;
                                    }
        }
    }
}
