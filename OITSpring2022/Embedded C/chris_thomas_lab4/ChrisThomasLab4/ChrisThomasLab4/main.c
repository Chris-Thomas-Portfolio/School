/*
 * ChrisThomasLab4.c
 *
 * Created: 4/19/2022 3:25:41 PM
 * Author : chris
 */ 

/*
Demo of using interrupts for doing what they do best --
two things at once.
Flashes LED0 at a fixed rate, interrupt toggles LED1 thru LED3 On and Off.
 */

#define F_CPU 16000000UL
#define ledmask 0x0E

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void){

PORTD |= 0x04;//activate pullup resistor on PD2
DDRB=0x0F;//set bottom 4 bits of PORTB as outputs

EIMSK |= (1<<INT0);//enable external interrupt 0 (digital pin 2 on UNO - PD2)
EICRA |= (1<<ISC01);//trigger interrupt on falling edge of signal into PD2
sei();//enable global interrupts

    /* blink LED 0 on and off - PB0 */
    while (1) 
    {
PORTB|=0x01;
_delay_ms(1000);
PORTB &=0xFE;
_delay_ms(1000);
    }
}

ISR(INT0_vect)//interrupt service routine for external interrupt 0
{
PORTB ^= ledmask;//toggle state of LEDs 1 thru 3 (PB1 thru PB3)
}


