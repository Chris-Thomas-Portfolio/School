/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: LCD_ChrisThomas.asm
Date: 3/25/2021 2:00:28 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: LCD Circuit

Abstract:
	This program will set up the LCD for use and display a message out to the LCD

Input:
	N/A

Output:
	PA0 - PA7 for the data to the LCD
	PB0 - PB2 for the Register Select, Read/Write, and Enable of LCD

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/

/************************Pseudo-Code************************************************
Setup the LCD for proper matrix
Wait for setup to complete
Turn on display and cursor
Wait for display and cursor to turn on
Clear LCD
Wait for LCD to clear
Get message and display on LCD
************************************************************************************/


.include "m32def.inc"
.equ LCD_DPRT = PORTA
.equ LCD_DDDR = DDRA
.equ LCD_DPIN = PINA
.equ LCD_CPRT = PORTB
.equ LCD_CDDR = DDRB
.equ LCD_CPIN = PINB
.equ LCD_RS = 0
.equ LCD_RW = 1
.equ LCD_EN = 2

;    Setting up stack
		ldi r21, high(ramend)
		out sph, r21
		ldi r21, low(ramend)
		out spl, r21

		ldi r21, 0xff
		out LCD_DDDR, r21			; set as output
		out LCD_CDDR, r21			; set as output
		cbi LCD_CPRT, LCD_EN		; enable LCD
		call DELAY_2ms				; call delay to allow for init

		LDI r16, 0x38				; init LCD for 2 lines a 5x7 matrix
		call CMNDWRT				; call the command write function
		call DELAY_2ms				; delay to allow time for process

		ldi r16, 0x0E				; Turn display on with cursor on
		call CMNDWRT				; call the command write function
		call DELAY_2ms				; delay to allow time for process

		ldi r16, 0x01				; Clear the LCD
		call CMNDWRT				; call the command write function
		call DELAY_2ms				; delay to allow time for process

		ldi r16, 0x06				; shift the cursor to the right
		call CMNDWRT				; call the command write function
		call DELAY_2ms				; delay to allow time for process

		ldi r31, HIGH(MSG << 1)		; z points at MSG
		ldi r30, LOW(MSG << 1)
Loop:
		lpm r16, z+
		cpi r16, 0					; make sure we have not hit null char
		breq Here					; if we have hit null char exit
		call DATAWRT				; call the data write function
		call DELAY_2ms				; delay to allow time for process
		rjmp Loop					; jump to Loop

Here:	jmp Here

CMNDWRT:
		out LCD_DPRT, r16			; set the LCD data port to r16
		cbi LCD_CPRT, LCD_RS		; set RS to = 0 for command
		cbi LCD_CPRT, LCD_RW		; set RW = 0 for write
		sbi LCD_CPRT, LCD_EN		; set EN = 1
		call SDELAY					; delay for 2 nop
		cbi LCD_CPRT, LCD_EN		; EN = 0 for high to low pulse
		call DELAY_100us			; call the delay function
		ret

DATAWRT:
		out LCD_DPRT, r16			; set the LCD data port to r16
		sbi LCD_CPRT, LCD_RS		; set RS to = 1 for command
		cbi LCD_CPRT, LCD_RW		; set RW = 0 for write
		sbi LCD_CPRT, LCD_EN		; set EN = 1
		call SDELAY					; delay for 2 nop
		cbi LCD_CPRT,LCD_EN			; EN = 0 for high to low pulse
		call DELAY_100us			; delay for 100 us
		ret

SDELAY:
		nop							; waste time
		nop
		ret

DELAY_100us:
		push r17					; delay for 100 us
		ldi r17,9
DR0:
		call SDELAY	
		dec r17
		brne DR0
		pop r17
		ret

DELAY_2ms:
		push r17					; delay for 2ms
		ldi r17, 20
LDR0:
		call DELAY_100us
		dec r17
		brne LDR0
		pop r17
		ret

MSG:								; message to be displayed
		.db "Hello World!", 0