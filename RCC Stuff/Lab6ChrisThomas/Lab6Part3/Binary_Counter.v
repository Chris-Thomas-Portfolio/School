module Binary_Counter(
	input [9:0] SW,
	output [7:0] LEDR
	);
	
	// the board only has ten switches, tie D7 and D6 inputs to 0 
	wire [7:0] data = {2'b00, SW[5:0]}; 
	
	up_down_counter c1 (
		.clk(SW[9]),
		.up_dn(SW[6]),
		.LD(SW[7]),
		.reset(SW[8]),
		.D(data),
		.Q(LEDR)
		);
		
endmodule  // sync_counter