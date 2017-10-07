#include <msp430.h>

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

        P1REN |= 0x08;
        P1DIR |= 0x01;
        P1DIR &= 0xF7;
        P1OUT |= 0x08;


        while (1){
            int i = P1IN & 0x08;
            if (i == 0){
                P1OUT ^= 0x01;
                __delay_cycles(50000);
            }
            else{
                P1OUT &= 0xFE;
            }
        }
}

