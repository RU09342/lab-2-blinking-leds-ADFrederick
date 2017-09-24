#include <msp430.h>     // Header file containing pin assignments

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    volatile int i;

    P1DIR = 0x01;
    P4DIR = 0x80;
    P1OUT = 0x01;
    P4OUT = 0x80;

    while(1){
        P1OUT ^= 0x01;
        for(i=0; i<4000; i++) {
                  if(i % 400 == 0) {
                      P4OUT ^=0x80;
                  }
        }
    }
}
