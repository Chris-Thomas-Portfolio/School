;
; Week2_32Atmega_Demo_ChrisThomas.asm
;
; Created: 1/22/2021 12:14:47 PM
; Author : Christopher Thomas
;

.include "m32def.inc"

.device atmega32

.def Temp =r16		; Temporary registar

.def Delay =r17		; Delay variable 1

.def Delay2 =r18	; Delay variable 2


;***** Initialization

RESET:
	
	ser Temp

	out DDRB,Temp	; Set PORTB to output

;***** Test input/output

LOOP:
	out PORTB,temp	; Update LEDS

	sbis PIND,0x00	; If (PORTD, pin0 == 0)

	swap Temp		; Then swap nibbles on LEDS

	sbis PIND,0x01	; If (PORTD, pin1 == 0)

	ror Temp		; Then rotate LEDS one right

	sbis PIND,0x02	; If (PORTD, pin2 == 0)
	
	rol Temp		; Then rotate LEDS one left

	sbis PIND,0x03	; If (PORTD, pin3 == 0)

	inc Temp		; Then count LEDS one down 

	sbis PIND,0x04	; If (PORTD, pin4 == 0)

	dec Temp		; Then count LEDS one up

	sbis PIND,0x05	; If (PORTD, pin5 == 0)

	com Temp;		; Then invert all LEDS and add 1

	sbis PIND,0x07	; If (PORTD, pin7 == 0)

	neg Temp		; Then swap nibbles on LEDS

;**** Now wait a while to make LED changes visible.

DLY:
	
	dec Delay

	brne DLY dec Delay2

	brne DLY

	rjmp LOOP		; Repeat loop forever