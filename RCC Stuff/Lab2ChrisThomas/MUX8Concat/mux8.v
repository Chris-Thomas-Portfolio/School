module mux8(
input wire [7:0] x,								//set x to input for x input
input wire [7:0] y,								//set y to input for y input
input wire s,										//set s to input for selector
output wire [7:0] m,								//set m to output
output [9:4] LEDR									//set LEDR to output for unused LEDs
);

assign LEDR = 6'b000000;						//set unused LEDs to low
assign m = {8{~s}} & x | {8{s}} & y;		//assign the output to x if ~s and y if s

endmodule