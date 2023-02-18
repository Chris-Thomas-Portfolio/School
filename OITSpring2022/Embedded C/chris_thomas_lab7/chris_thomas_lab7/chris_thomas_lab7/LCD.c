/*
 * LCD.c
 *
 * Created: 5/12/2022 3:41:40 PM
 *  Author: chris
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include <stdio.h>
#define LCD_data_dir	DDRD
#define  LCD_command_dir	DDRB
#define LCD_data_port	PORTD		//PORTD defined as DATA Port -> sends characters to LCD
#define LCD_command_port	PORTB	//PORTB defined as Port used to send Commands to LCD
#define RS	PB0	//Port B bit 0 defined as register select bit
#define RW	PB1	//Port B bit 1 defined as Read/Write' bit
#define EN	PB2	//Port B bit 2 is defined as Enable bit

void LCD_Init(void)
{
	/* Initialize LCD */
	LCD_command_dir = 0b00000111;	//PB0, PB1, PB2 set as output pins
	LCD_data_dir = 0b11111111;		//all bits in Port D defined as output pins
	_delay_ms(45);			// wait for internal initialization of LCD
	LCD_command(0x38);//sets 8-bit interface with LCD, 2 Line Display,5x8 dot character font	
	_delay_us(40);		
	LCD_command(0x0C);	//turns Display On with Cursor Off
	_delay_us(40);
	LCD_command(0x06);	//sets increment character position by one
	_delay_us(40);
	LCD_command(0x01);	//clears entire Display
	_delay_us(40);
	LCD_command(0x80);	//Sets Display to start at first character of first Line
	_delay_us(40);
}


void LCD_command (char cmnd)
{
	/*write a command to LCD */
	LCD_data_port = cmnd;
	LCD_command_port &= ~(1<<RS);	//sets RS bit Low -> Instruction Register
	LCD_command_port &= ~(1<<RW);	//sets R/W’ bit Low -> write
	LCD_command_port |= (1<<EN);	//sets EN bit High
	_delay_us(1);
	LCD_command_port &= ~(1<<EN); //Low going transition of EN bit Low writes data to LCD
	_delay_ms(2);					//give LCD time to complete write
}


void LCD_char(char char_data)
{
	/* write a character to LCD */
	LCD_data_port = char_data;
	LCD_command_port |= (1<<RS);	//sets RS bit High -> Data Register
	LCD_command_port &= ~(1<<RW);	//sets R/W’ bit Low -> write
	LCD_command_port |= (1<<EN);	//sets EN bit High
	_delay_us(1);
	LCD_command_port &= ~(1<<EN); //Low going transition of EN bit Low writes data to LCD
	_delay_ms(2);					//give LCD time to complete write
}


void LCD_string (char str[])
{
	/* Walks through a string a character at a time until
	finding a null terminator at the end of the string. Sends a character
     at a time to to function LCD_char */
	int i;
	for(i=0; str[i]!= 0; i++)
		{
			LCD_char (str[i]);
		}
}


void LCD_clear()
{
	LCD_command (0x01);
	_delay_us(40);
	
}