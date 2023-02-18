//filename: lab3.S
//author: Chris Thomas
//date: 10/23/2021
//purpose: Lab 03 - Stack/Subroutine 
    
#include<xc.h>
    
.global main
    
.set noreorder
    
.data
EXPR:	    .word 0x00000004	    //4
	    .word 0x00000003	    //3
	    .word 0x80000000 + '-'  //-
	    .word 0x00000002	    //2
	    .word 0x00000003	    //3
	    .word 0x80000000 + '*'  //*
	    .word 0x80000000 + '+'  //+
	    .word 0x80000000 + '='  //=
RESULT:	    .word 0x00000000
ERR:	    .word 0x00000000
    
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
    la s0, EXPR			    //&EXPR -> s0
    
    la s4, MULT_OP
    lw s4, 0(s4)
    
    la s5, ADD_OP
    lw s5, 0(s5)
    
    la s6, SUB_OP
    lw s6, 0(s6)
    
    la s7, EQ_OP
    lw s7, 0(s7)
    
    
    evaluate:
	    lw s1, 0(s0)	    //load element into s1
	    
	    beq s1, s4, is_mult	    //check if it is a multiply
	    nop
	    
	    beq s1, s5, is_add	    //check if it is a add
	    nop
	    
	    beq s1, s6, is_sub	    //check if it is a subtract
	    nop
	    
	    beq s1, s7, is_eq	    //check if it is a equals
	    nop
	    
	    slt s2, s1, zero	    //check if it is an error
	    bne s2, zero, is_error
	    nop
	    
	    is_num:
		push s1			//push number on stack
		j next_element
		nop
		
	    is_mult:			//move values to a registers and jump to multiply
		pop s1			//subroutine
		pop s2
		
		move a0, s2
		move a1, s1
		jal multiply
		nop
		
		push v0
		j next_element
		nop
	    
	    is_add:			//perform the addition
		pop s1
		pop s2
		
		addu s1, s1, s2
		push s1
		j next_element
		nop
		
	    is_sub:			//perform the subtraction
		pop s1
		pop s2
		
		subu s1, s2, s1
		push s1
		j next_element
		nop
		
	    is_eq:			//store final value and end program
		la s0, RESULT
		pop s3
		sw s3, 0(s0)
		
		j lab3_done
		nop
		
	    is_error:			//handle the error and end the program
		la s0, ERR
		li s3, 0xFFFFFFFF
		sw s3, 0(s0)
		
		j lab3_done
		nop
		
	    next_element:		//move to next element of array
		addiu s0, s0, 4
		j evaluate
		nop
		
		
lab3_done:
	j lab3_done
	nop
	
.end main

//**********************************************************
// subroutine: multiply
// purpose: performs the operation x + y through  a0 <- x, a1 <- y, result ->v0
.ent multiply
multiply:
    check_x:
    bgtz a0, check_y			   //check if x is zero
    nop
    
    x_is_zero:
	j end_multiply			   //if x is zero end multiply subroutine
	nop
	
    check_y:
	bgtz a1, y_not_zero		   //check if y is zero
	nop
	
    y_is_zero:
	j end_multiply			   //if y is zero end multiply subroutine
	nop 
	
    y_not_zero:				   //if y is not zero perform first addition
	move v0, a1
	addu a0, a0, -1
	
	multiply_loop:			   //continue addition until y is zero
	    addu v0, v0, a1
	    addu a0, a0, -1
	    
	    bgtz a0, multiply_loop
	    nop
end_multiply:	
	jr ra	  // return using register ra
	nop
.end multiply
//
////**********************************************************
    
    
    
    
    
    
    
    
    
    
    
    
//******************************************
//constants
MULT_OP: .word 0x80000000 + '*'
ADD_OP: .word 0x80000000 + '+'
SUB_OP: .word 0x80000000 + '-'
EQ_OP: .word 0x80000000 + '='