/*
 * chris_thomas_lab6.c
 *
 * Created: 5/11/2022 8:48:39 AM
 * Author : chris
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <math.h>	//math.h included for pow function
#include "stdio_setup.h"

int main(void)
{
	unsigned int ADC_data = 0;
	float ADC_voltage = 0.0;
	float Temperature = 0.0;
	
	ADMUX |= (1<<REFS0);	//AVcc (5V supply) used for Vref; Analog Channel 0 (ADC0) used as input; ADC result //is right justified
	DIDR0 |= (1<<ADC0D);	//Disables digital input buffer circuit of the ADC0 pin to reduce power consumption
	
	ADCSRA |= ((1<<ADEN) | (1<<ADSC) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));	//Enable ADC; Start ADC; Prescaler Value = 128; ADC Clock = 125 KHz
	
	UartInit();
	
	while (1)
	{

		if (!(ADCSRA & (1<< ADSC)));		//used if to check ADSC in register ADCSRA; ADSC will be 1    //as long as conversion in progress
		{

			ADC_data = ADC;	//reads the "number" produced by the ADC; reads all 10 bits right justified

			ADC_voltage = (5.0*ADC_data)/1024.0;//calculate the Analog Voltage (float) read by the ADC

			Temperature = -3.5549*pow(ADC_voltage, 3) + 27.625*pow(ADC_voltage, 2) -(89.697*ADC_voltage)+ 132.3;	//calculate the Temperature (float) from the Analog Voltage and the equation //shown on graph in lab handout

			printf("ADC_Output_Code = %4d Hex Value = 0x%03x  Voltage = %03f Temperature = %04f\r\n",ADC_data, ADC_data, ADC_voltage, Temperature);

			ADCSRA |= (1 << ADSC);//start another ADC conversion

			_delay_ms(5000);
		}

	}

}



