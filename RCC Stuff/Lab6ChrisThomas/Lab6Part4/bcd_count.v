module bcd_count(
	input [9:0] SW,
	output [0:6] HEX1, HEX0
	);
	
	wire [3:0] out;
	
		bcd_count_sub c1(
				.cen(SW[0]),
				.up_dn(SW[1]),
				.clk(SW[9]),
				.reset(SW[8]),
				.D(SW[5:2]),
				.data(out)
				);
	
		
		bcd_decimal bcd1(
				.SW(out),
				.HEX1(HEX1),
				.HEX0(HEX0)
				);
		
endmodule