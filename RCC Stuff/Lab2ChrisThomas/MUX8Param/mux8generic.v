module mux8generic
#(parameter N = 4)					//set parameter to 4 since we dont have enough inputs for 8
(input wire [N-1:0] x,				//make 4 x and y inputs
input wire [N-1:0] y,
input wire s,							//make 1 input for our selector
output reg [N-1:0] m,				//outputs for our mux
output [9:4] LEDR						//outputs for unused LEDs
);

assign LEDR = 6'b000000;			//drive unused LEDs low

always @(*)
	if(s == 0)							//if s equals 0 set m to x
		m = x;
	else									//otherwise set m to y
		m = y;
		
endmodule