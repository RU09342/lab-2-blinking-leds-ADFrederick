#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;
    P1DIR |= (0x01);    //Sets direction of P1 Bit 0 to Output
    P1DIR &= 0xFD;   //Sets direction of P1 Bit 1 to Input
    P1REN |= 0x02;    //Enables the resistor for P1 Bit 1
    P1OUT |= 0x02;    //Sets the ressistor for P1 Bit 1 to Pull Up

    int number = P1IN & BIT1;
    while(1){
       int number = P1IN & BIT1;
       if(number == 0){
           P1OUT |= 0x01;
       }else{
           P1OUT &= 0xFE;
       }

    }
    return 0;
}
