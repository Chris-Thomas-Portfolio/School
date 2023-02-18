/************************************************************************************
Programmer: C. Thomas
Organization: Rogue Community College -- Electronics Department
Filename: StepperMotorInterrupt_ChrisThomas.asm
Date: 3/24/2021 3:43:25 PM
Modifications: N/A
************************************************************************************/

/************************************************************************************
Lab Assignment: Stepper Motor with Interrupts

Abstract:
	This program will rotate CW or CCW depending on the input from a LDR it will use 
	interrupts to make the change.

Input:
	PD0

Output:
	PB0 - PB3

Device: Atmega32 @ 1.0MHz default internal RC frequency (configured in fuse tab within Studio)
************************************************************************************/
/******************************Pseudo-Code******************************************
Rotate the stepper motor CW while monitoring the brightness
If the brightness outside dims enough interrupt and begin rotating CCW
************************************************************************************/

.include "m32def.inc"

.org 0
	jmp reset				; reset and main program start at adress 0x00

.org 0x02
	jmp ex0_isr				; interrupt vector table 

reset:

.def step1 = r0 			; defining r0-r3 with easier to understand names
.def step2 = r1 
.def step3 = r2 
.def step4 = r3 

.def temp = r16 			; defining r16-r18 with easier to understand names
.def dly1 = r17  
.def dly2 = r18 

	ldi temp, high(ramend)	; put high byte of ramend into temp
	out sph, temp			; copies the high byte of ramend into stacker pointer
							; register high byte.
	
	ldi temp, low(ramend)	; put low byte of ramend into temp
	out spl, temp			; copies the low byte of ramend into stacker pointer
							; register low byte
							; top of stack at address 0x085f 

	ldi temp, 0x00			; load immediately $00 into temp
	out mcucr, temp			; configure mcucr for INT0 -- low logic .

	ser temp				; set all bits high in temp
	out ddrb, temp			; set PortB for output

							; using PB0 - PB3 for stepper motor

	sbi portd, 2			; pull-up resistor active on PD2 (INT0)
							; by default on reset Ports are input.

	ldi temp, 1<<int0		; shift 1 into int0 place -->$40
	out gicr, temp			; configure INT0 bit within gicr I/O reg.
							; for using INT0 interrupt

	ldi temp, 12			; put the step values into appropriate registers
	mov step1,temp			
	ldi	temp, 6	
	mov step2,temp
	ldi temp, 3
	mov step3, temp
	ldi temp, 9
	mov step4, temp



	sei						; set the global interrupt bit within SREG

cw:							; "main" program running prior to interrupt request

	out portb, step1		; send full-step code to portb 
	rcall delay1			; call delay1 (256 x 256) direction clockwise
	out portb, step2
	rcall delay1
	out portb, step3
	rcall delay1
	out portb, step4
	rcall delay1
	rjmp cw

delay1:

	dec dly1				; dly1 initial value = 0 then decrements to 255
	brne delay1				; Check if z-bit = 0 if no go back up to delay if yes drop through.

	dec dly2
	brne delay1				; check if both delay1 and delay2 are finished if not repeat if yes drop through.

	ret	

ex0_isr:					; when PD2 == 0 then execute CCW code at a faster rate
							
							; when PD2 != 0 return to CW 
							

	out portb, step4		; sending out full step in reverse for CCW
	rcall delay2			; delay2 is quicker
	out portb, step3
	rcall delay2
	out portb, step2
	rcall delay2
	out portb, step1
	rcall delay2


	reti					; after service routine completed return to main code."cw"

delay2:
		ldi dly1, 255
		ldi dly2, 5
		
wait2a:
		dec dly1
		brne wait2a
wait2b:
		dec dly2
		brne wait2b
		ret

;code uses concepts from textbook related to example text 10-5 pg377 
