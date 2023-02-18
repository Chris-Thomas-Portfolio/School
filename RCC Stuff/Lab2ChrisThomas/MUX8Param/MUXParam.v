module MUXParam(
input wire [7:0] x,				//make 8 inputs for x since we are doing an 8 line mux
input wire [7:0] y,				//make 8 inputs for y since we are doing an 8 line mux
input wire s,						//make s an input for our select
output wire [7:0] m,				//make 8 outputs for m since we are doing an 8 line mux
output wire [9:4] LEDR			//turn off unused LEDS
);

mux8generic #(

	.N(8))							//set the parameter
	
M8 (.LEDR(LEDR),					//make all the necessary connections to mux8generic
	.x(x),
	.y(y),
	.s(s),
	.m(m)
	
);

endmodule