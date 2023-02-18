/*
 * example5_1_atrausch.asm
 *
 *  Created: 1/27/2015 11:29:54 AM
 *   Author: Ann
 */ 



/*	ldi r21, 0xf5			;load immediately into r21 hex f5 -> 245d
	ldi r22, 0x0b			;load immediately into r22 hex 0b -> 11d
	add	r21, r22			; r21 = r22 + r21  0x0b + 0xf5 = 0x100 -> 256d*/

	//H, Z, and C are set.

	/*ldi r16, 0x33
	sts 0x400, r16			;get data into SRAM so you can bring it in to add

	lds r2, 0x400			;load value from SRAM 0x400 [0x33] -> 51d
	ldi r21, 0x55			;load immediately into r21 hex 0x55 -> 85d
	add r21, r2				; r21 = r2 + r21 0x33 + 0x55 -> 0x88 -> 136*/

	//No change on SREG bits

/*	ldi r16, 0x0A			;load immediately into r16 hex 0x0A -> 10d
	ldi r17, 0x0A			;load immediately into r17 hex 0x0A -> 10d
	mul r16, r17			;r16 = r17 + r16 -> 0x64 -> 100d


	ldi r16, 0xFA			;load immediately into r16 hex 0xFA -> 250d
	ldi r17, 0x0A			;load immediately into r17 hex 0x0A -> 10d
	mul r16, r17			;r16 = r17 + r16 -> 0x9c4 -> 2500d*/

	//No change on SREG bits

/*	ldi r16, 3
	ldi r17, 5
	add r17, r16

	ldi r16, 250
	adc r17, r16*/

	//C and H bits set in SREG total value 0x102 -> 258d


	//Example of a signed positive numbers being added together and the result is invalid too big
/*	ldi r20, 0x60
	ldi r21, 0x46
	add r20, r21*/



/*	ldi r20, -2
	ldi r21, -5
	add r20, r21*/

/*	ldi r20, -6
	ldi r21, 12
	add r20, r21*/



	ldi r20, 0x35
	andi r20, 0x0F


	ldi r21, 0x04
	ori r21, 0x30



	ldi r22, 0x54
	ldi r23, 0x78
	eor r23, r22

here: jmp here