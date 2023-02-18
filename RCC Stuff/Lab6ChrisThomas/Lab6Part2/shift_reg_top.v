module shift_reg_top(
	input [8:0] SW,
	output [5:1] LEDR
	);
	
	// instantiate submodule
	shift_reg s1(
		.L_R(SW[5]),
		.LD(SW[4]),
		.D(SW[3:0]),
		.sin(SW[6]),
		.clk(SW[7]),
		.reset(SW[8]),
		.Q(LEDR[5:2]),
		.sout(LEDR[1])
		);
		
endmodule  // shift_reg_top