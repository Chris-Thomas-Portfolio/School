/*
 * chris_thomas_lab3.c
 *
 * Created: 4/12/2022 3:55:23 PM
 * Author : chris
 */ 

// Defines
#define F_CPU 16000000UL

//The following definitions relate the Display Segment
// Name to the hex code used to "light up" that segment
#define A  0x01
#define B  0x02
#define C  0x04
#define D  0x08
#define E  0x10
#define F  0x20
#define G  0x80

// Include Files
#include <avr/io.h>
#include <util/delay.h>

int i;
int main(void)
{

	DDRB = 0x3F;//sets pins 0 thru 5 of PORTB as OUTPUTS
	DDRD = DDRD | 0xFC;//PD7(output)->segment G; PD4(output)->buzzer; PD2(input)->switch
	//DDRD = (DDRD & 0x20);//sets PD5 as an input leaves other bits unchanged
	PORTD=PORTD | 0x04;//turns on pullup resistor connected to pd2
	_delay_ms(1);
	while((PIND & 0x04)){}//wait for button to be pressed
	
	
	//for loop steps through cases 0 through 9
	//each case produces a number 0 through 9 on the display
	//the numbers are displayed in reverse order
	//9,8,7,6,5,4,3,2,1,0
	for (i=0;i<16;i++)
	{
		switch (i)
		{
			case 0:		//number zero
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|B|C|D|E|F; //turn on display segments controlled by PORTB
			_delay_ms(1000);
			break;
			
			case 1:	//number 1
			PORTB=0x00;	//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F; //turn off segment G connected to PORTD
			PORTB = B|C;	//turn on display segments controlled by PORTB
			_delay_ms(1000);
			break;
			
			case 2:	//number 2
			PORTB=0x00;	//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F; //turn off segment G connected to PORTD
			PORTB = A|B|E|D;	//turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 3:		//number 3
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|B|C|D;	//turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 4:		//number 4
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = B|C|F;	//turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 5:		//number 5
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|C|D|F;	//turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 6:		//number 6
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = C|D|E|F;	//turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 7:		//number 7
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|B|C;	//turn on display segments controlled by PORTB
			_delay_ms(1000);
			break;
			
			case  8:		//number 8
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|B|C|D|E|F; //turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 9:		//number 9
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|B|C|F;	//turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 10:
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|B|C|E|F; //turn on display segments controlled by PORTB
			PORTD = PORTD | G;	//turn on display segment controlled by PORTD
			_delay_ms(1000);
			break;
			
			case 11:
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = F|E|D|C;
			PORTD = PORTD | G;
			_delay_ms(1000);
			break;
			
			case 12:
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|E|F|D;
			_delay_ms(1000);
			break;
			
			case 13:
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = B|C|D|E;
			PORTD = PORTD | G;
			_delay_ms(1000);
			break;
			
			case 14:
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|F|E|D;
			PORTD = PORTD | G;
			_delay_ms(1000);
			break;
			
			case 15:
			PORTB=0x00;		//turn off all segments connected to PORTB
			PORTD=PORTD & 0x7F;	//turn off segment G connected to PORTD
			PORTB = A|F|E;
			PORTD = PORTD | G;
			_delay_ms(1000);
			break;
			
		}
		
		
	}
	
	PORTD =(PORTD | 0x10);		//turn on active buzzer
	_delay_ms(1000);			//wait for one second
	PORTD = (PORTD & 0xEF);		//turn off active buzzer
	
	while(1)
	{
	}
	
}



