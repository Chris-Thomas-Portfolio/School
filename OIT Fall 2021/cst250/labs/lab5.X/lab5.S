//filename: lab5.S
//author: Chris Thomas
//date: 11/18/2021
//purpose: Lab 05 - Function Calls in C Style
    
#include<xc.h>
    
.global main
    
.set noreorder
    
.data
    decimal:	 .space 11
    count:	 .byte 0x0C
.text
//*********************************************************
//macro name: push
//parameters: register
//purpose: decrements sp by one word(4 bytes) and stores
//	    contents of selected register to stack.
.macro push reg
    addiu sp, sp, -4
    sw \reg, 0(sp)
.endm
    
//**********************************************************
//macro name: pop
//paramaters: register
//purpose: load contents of address pointed to by the stack
//	    pointer to \reg and increment sp by 4 bytes (one word)
.macro pop reg
    lw \reg, 0(sp)
    addiu sp, sp, 4
.endm
    
//main routine
.ent main
    
main:
    //set up stack
    addiu sp, sp, -68
    sw ra, 64(sp)
    sw fp, 60(sp)
    move fp, sp
    
    li t0, 0
    sw t0, 56(fp)
    sw t0, 52(fp)
    sw t0, 48(fp)
    sw t0, 44(fp)
    sw t0, 40(fp)
    sw t0, 36(fp)
    sw t0, 32(fp)
    sw t0, 28(fp)
    sw t0, 24(fp)
    sw t0, 20(fp)
    sw t0, 16(fp)
    sw t0, 12(fp)
    sw t0, 8(fp)
    sw t0, 4(fp)
    sw t0, 0(fp)
    
    //configure UART TX
	la t9, U1MODESET
	li t0, 0x8000
	sw t0, 0(t9)
	
	la t9, U1STASET
	li t0, 0x1400
	sw t0, 0(t9)
    
	la s0, string_constant
	
    process_string_loop:
	lb s1, 0(s0)
	//if s1 is equal to zero jump to process_string_loop_done
	beqz s1, process_string_loop_done
	nop
	
	move a0, s1
	//jump and link to is_a_digit
	jal is_a_digit
	nop
	//if v0 is equal to 0xFFFFFFF jump to increment_loop
	beq v0, 0xFFFFFFFF, increment_loop
	nop
	//Calculate where in stack the appropriate value is and increment
	li s2, 16
	li s3, 4
	mul s3, v0, s3
	addu s2, s3, s2
	addu s2, s2, fp
	lw s3, 0(s2)
	addiu s3, s3, 1
	sw s3, 0(s2)
	lw s3, 56(fp)
	addiu s3, s3, 1
	sw s3, 56(fp)
	//increment
    increment_loop:
	addiu s0, s0, 1
	j process_string_loop
	nop
	
    process_string_loop_done:
	
	li t9, 0

	begin_loop:
	la a0, string_begin	//load address of string_begin into a0
	jal output_string	//jump and link to output_string
	nop

	la a1, decimal		//load address of decimal to a1
	move a0, t9		//move a0 into t9
	jal binary_to_asciidec	//jump and link to binary_to_asciidec
	nop
	la a0, decimal		//load adress of decimal into a0
	jal output_string	//jump and link to output_string
	nop

	la a0, string_number	//load address of string_number into a0
	jal output_string	//jump and link to output_string
	nop
	
	//calculate stack
	li s2, 16		//load immediate 16 into s2
	li s3, 4		//load immediate 4 into s3
	mul s3, s3, t9		//multiply s3 by t9 and store in s3
	addu s2, s3, s2		//add unsigned s2 and s3 and store in s2
	addu s2, s2, fp		//add unsigned s2 with FP and store in s2
	lw a0, 0(s2)		//load word a0 into s2
	la a1, decimal		//load adress of decimal into a1
	jal binary_to_asciidec	//jump and link to binary_to_asciidec
	nop

	la a0, decimal		//load adress of decimal into a0
	jal output_string	//jump and link to output_string
	nop

	la a0, new_line		//load adress of new_line into a0
	jal output_string	//jump and link to output_string
	nop

	addu t9, t9, 1		//increment t9
	li t8, 10		//load immediate 10 to t8
	beq t9, t8, last_line	//branch if t9 and t8 are equal to last_line
	nop
	j begin_loop		//jump to begin_loop
	nop

	last_line:
    la a0, strtot		//load address of strtot into a0
    jal output_string		//jump and link to output_string
    nop

    la a1, decimal		//load address of decimal into a1
    lw a0, 56(fp)		//lw a0 into 56(fp)
    jal binary_to_asciidec	//jump and link to binary_to_ascii
    nop

    la a0, decimal		//load address of decimal into a0
    jal output_string		//jump and link to output_string
    nop



    endless_loop:
    j endless_loop		//endless loop to end program
    nop
.end main
	
.ent binary_to_asciidec
//**********************************************************
// subroutine: binary_to_asciidec
// purpose: Converts binary value to the appropriate ascii value
//**********************************************************
binary_to_asciidec:
    //setting up stack
    addiu sp, sp, -8
    sw ra, 4(sp)
    sw fp, 0(sp)
    move fp, sp
    
    li t0, 0x00
    push t0
    
    li t0, 10
    move t1, a0
    
    convert_loop:
    //convert value to ascii value
	divu t1, t0
	mflo t1
	mfhi t2
	addiu t2, 0x30
	push t2
	bnez t1, convert_loop
	nop
    pop_to_string_loop:
    //pop value to string
	pop t0
	sb t0, 0(a1)
	addiu a1, a1, 1
	bnez t0, pop_to_string_loop
	nop
	
	move sp, fp
	lw ra, 4(sp)
	lw fp, 0(sp)
	addiu sp, sp, 8
	
	jr ra
	nop
.end binary_to_asciidec
	
.ent is_a_digit
//**********************************************************
// subroutine: is_a_digit
// purpose: determines if giving byte is a digit or not	
//**********************************************************
is_a_digit:
    addiu sp, sp, -8
    sw ra, 4(sp)
    sw fp, 0(sp)
    move fp,sp
    //determine if it is a digit or not
    li t0, 0x30
    blt a0, t0, not_digit
    nop
    
    li t0, 0x39
    bgt a0, t0, not_digit
    nop
    
    li t0, 0x30
    subu a0, a0, t0
    move v0, a0
    j is_a_digit_done
    nop
    //return 0xFFFFFFFF if not a digit
    not_digit:
	li v0, 0xffffffff
    //when digit is done clean up stack and return
is_a_digit_done:
    move sp, fp
    lw ra, 4(sp)
    lw fp, 0(sp)
    addiu sp, sp, 8
    
    jr ra
    nop
.end is_a_digit
    
.ent output_string
//**********************************************************
// subroutine: output_string
// purpose: Handles the output to UART
//**********************************************************
output_string:
    //set up stack
    addiu sp, sp, -8
    sw ra, 4(sp)
    sw fp, 0(sp)
    move fp, sp
    //load byte into t0
    get_byte:
    lb t0, 0(a0)
    beq t0, zero, done //branch to done if t0 is equal to zero
    nop
    //display in UART TX
    send:
    la t2, U1TXREG
    sw t0, 0(t2)
    
    la t2, U1STA
    //delay for UART TX
    wait_tx:
    lw t1, 0(t2)
    andi t1, t1, 0x100
    beq t1, zero, wait_tx
    nop
    //increment a0 and jump to get_byte
    next:
    addu a0, a0, 1
    j get_byte
    nop
    //when done clean up stack and return
    done:
    move sp, fp
    lw ra, 4(sp)
    lw fp, 0(sp)
    addiu sp, sp, 8
    
    jr ra
    nop
.end output_string
// CONSTANTS    ******************************************
string_constant: .asciiz "There are 10 kinds of people in the world, those who understand binary and those who don't. The rest of the 0-9 digits are 2, 3, 4, 5, 6, 7, 8, 9."
string_begin: .asciiz "Number of "
string_number: .asciiz "'s: "
strtot: .asciiz "\n\nTotal number of digits: "
new_line: .asciiz "\r\n"
