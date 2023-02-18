module fourbit_addsub_top(
input [9:0] SW,
output [9:0] LEDR
);

assign LEDR[9:4] = 6'b000000;

addsub AS1( //Instatiate addsub submodule
	.a(SW[3:0]),
	.b(SW[7:4]),
	.add_sub(SW[8]),
	.clk(SW[9]),
	.result(LEDR[3:0])
	);

endmodule
