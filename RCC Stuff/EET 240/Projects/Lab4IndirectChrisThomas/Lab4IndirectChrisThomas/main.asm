/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: Lab4IndirectChrisThomas.asm
Date: 2/26/2021 2:44:02 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Lab 4 Indirect 7-Segment

Abstract:
	This program looks for a button press if the button is pressed it increases the count
	and sends out the necessary value to portb to show the correct value on the 7-seg
	display.

Input:
	portd

Output:
	portb

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
.include "m32def.inc"

/*Initialization*/

.def temp = r16
.def counter = r17

//setup portb for output
	ser temp
	out ddrb, temp

	ldi r20, 0b00111111		; '0' starting value for display
	out portb, r20

//setup portd for input
	clr temp
	out ddrd, temp

//enable pull-up for PD0
	ldi temp, 0b00000001
	out portd, temp

//setup stack pointer 
	ldi temp, HIGH(RAMEND)
	out sph, temp
	ldi temp, LOW(RAMEND)
	out spl, temp

//setup 7-segment display array for 1-9 numbers
/*  a
    --
 f|    | b
	--
	g
 e|		| c
    --
    d

	*/

//0b dp-g-f-e-d-c-b-a
	ldi r21, 0b00000110		; '1'
	ldi r22, 0b01011011		; '2'
	ldi r23, 0b01001111		; '3'
	ldi r24, 0b01100110		; '4'
	ldi r25, 0b01101101		; '5'
	ldi r26, 0b01111101		; '6'
	ldi r27, 0b00000111		; '7'
	ldi r28, 0b01111111		; '8'
	ldi r29, 0b01100111		; '9'

	clr ZL					; clear pointer register
	clr ZH

	clr counter				; track number of button presses

/*********************************** Main ****************************************/
start:
	sbic pind, 0			; if button is pushed skip next line
	rjmp start				; go back to start if no button pushed

	inc counter				; increment the counter

	cpi counter, 10			; check if counter is 10
	brne pc + 2				; if not skip the clear counter command
	clr counter

	ldi zl, 20				; points Z-register to R20 address
	add zl, counter			; increment zl by 1 each time through loop

	ld temp, z				; load temp with value pointed at by z
	out portb, temp			; send temp out to portb
	;rjmp start				; part 1 of lab just jump up to start and see how the display is functioning
							; hopefully your answer is not great

							; comment out this rjmp start statement and add the ReleaseWait code to the project
							; re-compile and see how the display operates?
    
	

ReleaseWait:
	sbis pind, 0			; wait for the button to be released
	rjmp ReleaseWait		; check for button release
	rjmp start				; if yes go back to start

/*   Hardware Interface Circuit:
SSD PMOD
AA, AB, AC, AD, AE, AF, AG are combined individual segments for both displays
VCC (2.7V to 5.25V max (recommended 3.3V)
GND
CAT (enables the display to be on alternating between each display
VCC and GND can be connected to an unused port's VCC and GND pins  */