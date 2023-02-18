module MUX2to1a (
	input wire x, y, z,								// set x, y, and z as inputs
	output wire m,										// set m as an output
	output [9:1] LEDR);								// LEDR as output for unused LEDS

	assign m = (z == 1'b0) ? x :					// assign m to x or y depending on z
				  (z == 1'b1) ? y :
				  1'bX;
				  
	assign LEDR [9:1] = 8'b00000000;				// assign unused LEDs to low
			
endmodule