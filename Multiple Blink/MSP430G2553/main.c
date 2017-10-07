#include <msp430.h>     // Header file containing pin assignments

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    volatile int i;

    P1DIR = 0x41;
    P1OUT = 0x41;

    while(1){
          for(i=0; i<4000; i++) {
                  if(i % 400 == 0) {
                      P1OUT ^=0x40;
                  }
                  if (i % 2105 == 0){
                      P1OUT ^= 0x01;
                  }
        }
    }
}
