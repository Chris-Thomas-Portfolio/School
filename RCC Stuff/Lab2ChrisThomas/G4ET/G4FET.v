module G4FET(
	
	input [2:0] x,										// set x as 3 inputs
	output [9:1] LEDR,								// set LEDR as an output for unused LEDs
	output z												// set z as an output
	
);

	assign z = (~x[0] & ~x[1])						//assign z to the different values possible
					| (~x[0] & ~x[2])
					| (~x[1] & ~x[2]);
					
	assign LEDR [9:1] = 8'b00000000;				//set unused LEDs to low

endmodule					