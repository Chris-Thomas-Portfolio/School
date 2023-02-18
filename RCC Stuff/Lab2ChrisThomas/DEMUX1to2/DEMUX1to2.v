module DEMUX1to2(
input wire a,
input wire Sel,
output reg y,
output reg z,
output [9:1] LEDR
);

always @(*)
	if (Sel == 0)						// if Sel is equal to 0 then the output on y will be a
		y = a;
	else									// if Sel is 1 then the output on z will be a
		z = a;
		
assign LEDR[8:1] = 7'b0000000;	// set the unused LEDs to low

endmodule 