//filename: lab1c.S
//authoer: Chris Thomas
//date: 10/7/2021
//purpose: Lab 01 C - 
    
#include <xc.h>

.global main
.set noreorder
    
    
.data
    var_a:.word 0x7fffffff
    var_b:.word 0x10000000
    var_c:.word
    
.text
.ent main
    main:
	la t0,var_a //load address of var_a into t0
	lw t0,0(t0) //store value of var_a into t0
	
	la t1,var_b //load address of var_b into t1
	lw t1,0(t1) //store value of var_b into t1
	
	add t0,t0,t1	//add t0 and t1 and store in t0
	
	la t1,var_c //load address of var_c into t1
	sw t0,0(t1) //stores the value of t0 into var_c
    loop:
	j loop
	nop
    
.end main
    