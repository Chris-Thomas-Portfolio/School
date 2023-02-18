module MUX2to1c(
input wire e,									// set e, f, g as inputs
input wire f,
input wire g,
output reg h,									// set h as an output register
output [9:1]LEDR								// set LEDR as output for unused LEDs
);

	always @(*)
		if (g < 1)								// if g is less than 1 set h to e
			h = e;
		else										// if g is not less than 1 set h to f
			h = f;
			
assign LEDR [9:1] = 8'b00000000;			// assign unused LEDs to low
					
endmodule