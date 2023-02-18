module bcd7seg(B,H);
	
	input [3:0] B;			//declare 4 inputs for switches
	output [0:6] H;		//declare 7 outputs for 7-segment displays
	
	
	wire [0:6] H;			//intermediate wire connection to connec displays
	
	assign H[0] = (~B[3] & B[2] & ~B[1] & ~B[0]) | (~B[3] & ~B[2] & ~B[1] & B[0]);
	assign H[1] = (~B[3] & B[2] & B[1] & ~B[0]) | (~B[3] & B[2] & ~B[1] & B[0]);
	assign H[2] = (~B[3] & ~B[2] & B[1] & ~B[0]);
	assign H[3] = (~B[3] & ~B[2] & ~B[1] & B[0]) | (~B[3] & B[2] & ~B[1] & ~B[0]) | (~B[3] & B[2] & B[1] & B[0]);
	assign H[4] = (~B[3] & ~B[2] & ~B[1] & B[0]) | (~B[3] & ~B[2] & B[1] & B[0]) | (~B[3] & B[2] & ~B[1] & ~B[0]) | (~B[3] & B[2] & ~B[1] & B[0]) | (~B[3] & B[2] & B[1] & B[0]) | (B[3] & ~B[2] & ~B[1] & B[0]);
	assign H[5] = (~B[3] & ~B[2] & ~B[1] & B[0]) | (~B[3] & ~B[2] & B[1] & ~B[0]) | (~B[3] & ~B[2] & B[1] & B[0]) | (~B[3] & B[2] & B[1] & B[0]);
	assign H[6] = (~B[3] & ~B[2] & ~B[1] & ~B[0]) | (~B[3] & ~B[2] & ~B[1] & B[0]) | (~B[3] & B[2] & B[1] & B[0]);
	
endmodule