#include <msp430.h>

void main(void)
{
        WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

        P2REN |= 0x02;
        P1REN |= 0x02;
        P1DIR |= 0x01;
        P1DIR &= 0xFD;
        P2DIR &= 0xFD;
        P4DIR |= 0x80;
        P1OUT |= 0x03;
        P2OUT |= 0x02;
        P4OUT |= 0x08;

        while (1){
            int i = P2IN & 0x02;
            int j = P1IN & 0x02;
            if (i == 0){
                if (j == 0){
                    P1OUT ^= 0x01;
                    P4OUT &= 0x7F;
                    __delay_cycles(50000);
                }
                else{
                    P1OUT &= 0xFE;
                    P4OUT ^= 0x80;
                    __delay_cycles(50000);
                }

            }
            else{
                if (j == 0){
                    P1OUT ^= 0x01;
                    P4OUT ^= 0x80;
                    __delay_cycles(50000);
                }
                else{
                    P1OUT &= 0xFE;
                    P4OUT &= 0x7F;

                }

            }
        }
}
