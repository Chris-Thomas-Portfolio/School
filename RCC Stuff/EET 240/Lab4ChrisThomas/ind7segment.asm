;
; ind7segment.asm
;
; Created: 1/29/2021 2:44:40 PM
; Author : Ann
;


; Replace with your application code

.include "m32def.inc"

/*Initialization*/

.def temp = r16
.def counter = r17

//setup portb for output
	ser temp
	out ddrb, temp

	ldi r20, 0b00111111		; '0'	inital value out to 7-segment display
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

	clr ZL					; clear pointer register for SRAM
	clr ZH

	clr counter				;track number of button presses

/***********************************	Main ****************************************/
start:
	sbic pind, 0			;check for button press?
	rjmp start				;no go back

	inc counter				;yes, add 1 to counter

	cpi counter, 10			;is counter = 10?
	brne pc + 2				;no, skip clearing counter command
	clr counter

	ldi zl, 20				;points Z-register to R20 address
	add zl, counter			;increment zl by 1 each time through loop

	ld temp, z				;load temp with value pointed at by z
	out portb, temp			;send value out to portb
	rjmp start				; part 1 of lab just jump up to start and see how the display is functioning
							; hopefully your answer is not great

							; comment out this rjmp start statement and add the ReleaseWait code to the project
							; re-compile and see how the display operates?
    
	

;ReleaseWait:
	;sbis pind, 0			;wait for button to be released
	;rjmp ReleaseWait		;check for button release
	;rjmp start				;yes, go back to start

/*   Hardware Interface Circuit:
SSD PMOD
AA, AB, AC, AD, AE, AF, AG are combined individual segments for both displays
VCC (2.7V to 5.25V max (recommended 3.3V)
GND
CAT (enables the display to be on alternating between each display
VCC and GND can be connected to an unused port's VCC and GND pins  */
