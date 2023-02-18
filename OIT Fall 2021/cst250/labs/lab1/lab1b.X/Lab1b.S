//filename: lab1b.S
//authoer: Chris Thomas
//date: 10/7/2021
//purpose: Lab 01 B - Adds 2 numbers and then subtracts a third from that sum and stores
    //			it in a variable. Then adds 2 more numbers together and stores 
    //			that value in a different variable.
    
#include <xc.h>

.global main
.set noreorder
    
    
.data
    var_a:.word 0x7fffffff //creates a variable var_a, 4 bytes, and inits it
    var_b:.word 0x10000000 //creates a variable var_a, 4 bytes, and inits it
    var_c:.space 4  //makes uninit variable with .space 
    var_d:.space 4  //makes uninit variable with .space
    
.text

.ent main
    main:
        li t0,0x20000000 //loads the value 0x2000000 into t0 register
	la t1,var_c	    //loads the address of var_c into t1
	sw t0,0(t1)	    //store the value of t0 into var_c
	
	la t0,var_a	    //loads the address of var_a into t0
	lw t0,0(t0)	    //store the value of var_a into t0

	la t1,var_b	    //loads the address of var_b into t1
	lw t1,0(t1)	    //store the value of var_b into t1
	
	addu t0,t0,t1   //add var_a and var_b store in t0
	
	la t1,var_c	    //loads the address of var_c into t1
	lw t1,0(t1)	    //store the value of var_c into t1

	subu t0,t0,t1   //subtract var_c from the sum off var_a and var_b and store it in t0

	la t1,var_d	    //loads the address of var_d into t5
	sw t0,0(t1)	    //store the value of t1 into var_d
	
	la t0,var_b	    //loads the address of var_b into t0
	lw t0,0(t0)	    //store the value of var_b into t0
	
	la t1,var_c	    //loads the address of var_c into t1
	lw t1,0(t1)	    //store the value of var_c into t1
	
	addu t0,t0,t1	    //add var_a and var_b store in t0
	
	la t1,var_a	    //loads the address of var_a in t1
	sw t0,0(t1)	    //store the value of t0 in var_a
	

    loop:
	j loop
	nop
.end main