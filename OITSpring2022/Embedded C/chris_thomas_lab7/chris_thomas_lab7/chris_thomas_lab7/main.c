/*
 * 
 *
 * Created: 4/25/2020 10:05:04 AM
 * Author : Deyr & Drouantg
 *Modified: 5/8/2022
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#include "LCD.h" 

#define LCD_data_dir	DDRD
#define  LCD_command_dir	DDRB
#define LCD_data_port	PORTD		//PORTD defined as DATA Port -> sends characters to LCD
#define LCD_command_port	PORTB	//PORTB defined as Port used to send Commands to LCD
#define RS	PB0	//Port B bit 0 defined as register select bit
#define RW	PB1	//Port B bit 1 defined as Read/Write' bit
#define EN	PB2	//Port B bit 2 is defined as Enable bit



int main(void)
{
	
	char result[10];
	unsigned int ADC_data = 0;
	float ADC_voltage = 0.0;
	float Temp = 0.0;
	ADMUX = (1<<REFS0);//5V supply used for Vref; Analog Channel 0 (ADC0) used as input; ADC result is right justified
	DIDR0 = (1 <<ADC0D);//Disables digital input buffer circuit of the ADC0 pin to reduce power consumption
	//Enable ADC; Start ADC; Prescaler Value = 128; ADC Clock = 125 KHz
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (1<<ADPS2) | (1<<ADPS1) |(1<<ADPS0);
	
	LCD_Init();//initializes LCD, clears display and points to position of first character in display's first line

	while (1)
	{
		if (!(ADCSRA & (1<< ADSC)))//ADSC in register ADCSRA will be 1 as long as conversion in progress
		{
			ADC_data = ADC;//read ADC_Output Code
			ADC_voltage = (5.0*ADC_data)/1024.0;//calculate Analog Voltage into ADC;type conversion of ADC_data from int to float
			Temp = ((-3.5549*(pow(ADC_voltage,3)))+(27.625*(pow(ADC_voltage,2)))+((-89.697)*((ADC_voltage)))+132.3);
			LCD_clear();	//clears display and points to position of first character in display's first line
			LCD_string("Temperature =");//print string constant to LCD
			sprintf(result,"%.2f",Temp);//stores float "Temp" in str array "result"
			LCD_command(0xC0);//go to first char of the 2nd line of the display
			LCD_string(result);//prints contents of "result" to screen
			_delay_ms(1000);
					
		}
		
		ADCSRA |= (1 << ADSC);//start another ADC conversion
		_delay_ms(1000);
	}
	
    while (1) 
    {
    }
	return 0;
}
