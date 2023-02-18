module MUX2to1b(
	input wire a,								// set a as an input
	input wire b,								// set b as an input
	input wire s,								// set s as an input
	output reg y,								// set y as an output register
	output [9:1] LEDR							// set LEDR as output for unused LEDs
);

	always @(*)									// always check the state of these things under this statement
		if(s == 0)
			 y = a;								// if s is 0 set y to a
		else 
			 y = b;								// if s is not 0 set y to b
			 
assign LEDR [9:1] = 8'b00000000;			// assign unused LEDs to low
			
endmodule