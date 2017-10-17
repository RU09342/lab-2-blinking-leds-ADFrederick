#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= 0x01;    //Sets direction of P1 Bit 0 to Output
    P5DIR &= 0xBF;   //Sets direction of P5 Bit 6 to Input
    P5REN |= 0x40;    //Enables the resistor for P5 Bit 6
    P5OUT |= 0x40;    //Sets the ressistor for P5 Bit 6 to Pull Up

    while(1){
       int number = P5IN & BIT6;
       if(number == 0){
           P1OUT |= 0x01;
       }else{
           P1OUT &= 0xFE;
       }

    }

    return 0;
}
