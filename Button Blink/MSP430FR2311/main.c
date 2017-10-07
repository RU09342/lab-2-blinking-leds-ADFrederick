#include <msp430.h>

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
        PM5CTL0 &= ~LOCKLPM5;  //ENABLE GPIO

        P1REN |= 0x02;
        P1DIR |= 0x01;
        P1DIR &= 0xFD;
        P1OUT |= 0x03;


        while (1){
            int i = P1IN & 0x02;
            if (i == 0){
                P1OUT ^= 0x01;
                __delay_cycles(50000);
            }
            else{
                P1OUT &= 0xFE;
            }
        }
}

