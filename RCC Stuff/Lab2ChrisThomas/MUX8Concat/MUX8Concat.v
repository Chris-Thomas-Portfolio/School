module MUX8Concat(
input wire [7:0] x,				//set x to input for x input
input wire [7:0] y,				//set y to input for y input
input wire s,						//set s to input for selector
output wire [7:0] m,				//set m to output for mux output
output wire [9:4] LEDR			//set LEDR to output for unused LEDs
);

mux8 M8 (.LEDR(LEDR),			//set LEDR to LEDR of mux8
		.x(x),						//set x to x of mux8
		.y(y),						//set y to y of mux8
		.s(s),						//set s to s of mux8
		.m(m)							//set m to m of mux8
	
);

endmodule